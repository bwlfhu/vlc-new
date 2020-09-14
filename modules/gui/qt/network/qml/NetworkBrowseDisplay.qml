/*****************************************************************************
 * Copyright (C) 2019 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * ( at your option ) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtQml 2.11
import QtGraphicalEffects 1.0

import org.videolan.vlc 0.1
import org.videolan.medialib 0.1

import "qrc:///util/" as Util
import "qrc:///widgets/" as Widgets
import "qrc:///style/"

Widgets.NavigableFocusScope {
    id: root

    property alias tree: providerModel.tree
    readonly property var currentIndex: view.currentItem.currentIndex
    //the index to "go to" when the view is loaded
    property var initialIndex: 0

    NetworkMediaModel {
        id: providerModel
        ctx: mainctx
        tree: undefined
        onCountChanged: resetFocus()
    }

    Util.SelectableDelegateModel{
        id: selectionModel
        model: providerModel
    }

    function resetFocus() {
        var initialIndex = root.initialIndex
        if (initialIndex >= providerModel.count)
            initialIndex = 0
        selectionModel.select(providerModel.index(initialIndex, 0), ItemSelectionModel.ClearAndSelect)
        if (view.currentItem) {
            view.currentItem.currentIndex = initialIndex
            view.currentItem.positionViewAtIndex(initialIndex, ItemView.Contain)
        }
    }


    function _actionAtIndex(index) {
        if ( selectionModel.selectedIndexes.length > 1 ) {
            providerModel.addAndPlay( selectionModel.selectedIndexes )
        } else {
            var data = providerModel.getDataAt(index)
            if (data.type === NetworkMediaModel.TYPE_DIRECTORY
                    || data.type === NetworkMediaModel.TYPE_NODE)  {
                history.push(["mc", "network", { tree: data.tree }]);
            } else {
                providerModel.addAndPlay( selectionModel.selectedIndexes )
            }
        }
    }

    Widgets.MenuExt {
        id: contextMenu
        property var selectionModel: undefined
        property var model: ({})
        closePolicy: Popup.CloseOnReleaseOutside | Popup.CloseOnEscape
        focus:true

        Instantiator {
            id: instanciator
            property var modelActions: {
                "play": function() {
                    if (selectionModel) {
                        providerModel.addAndPlay(selectionModel.selectedIndexes )
                    }
                    contextMenu.close()
                },
                "enqueue": function() {
                    if (selectionModel) {
                        providerModel.addToPlaylist(selectionModel.selectedIndexes )
                    }
                    contextMenu.close()
                },
                "index": function(index) {
                    contextMenu.model.indexed = contextMenu.model.indexed
                    contextMenu.close()
                }
            }

            model: [{
                    active: true,
                    text: i18n.qtr("Play"),
                    action: "play"
                }, {
                    active: true,
                    text: i18n.qtr("Enqueue"),
                    action: "enqueue"
                }, {
                    active:  contextMenu.model && !!contextMenu.model.can_index,
                    text: contextMenu.model && contextMenu.model.indexed ? i18n.qtr("Remove from Media Library") : i18n.qtr("Add to Media Library") ,
                    action: "index"
                }
            ]

            onObjectAdded: model[index].active && contextMenu.insertItem( index, object )
            onObjectRemoved: model[index].active && contextMenu.removeItem( object )
            delegate: Widgets.MenuItemExt {
                focus: true
                text: modelData.text
                onTriggered: {
                    if (modelData.action && instanciator.modelActions[modelData.action]) {
                        instanciator.modelActions[modelData.action]()
                    }
                }
            }
        }

        onClosed: contextMenu.parent.forceActiveFocus()
    }


    Component{
        id: gridComponent

        Widgets.ExpandGridView {
            id: gridView

            delegateModel: selectionModel
            model: providerModel

            headerDelegate: Widgets.NavigableFocusScope {
                width: view.width
                height: layout.implicitHeight + VLCStyle.margin_large + VLCStyle.margin_normal
                navigable: btn.visible

                RowLayout {
                    id: layout

                    anchors.fill: parent
                    anchors.topMargin: VLCStyle.margin_large
                    anchors.bottomMargin: VLCStyle.margin_normal
                    anchors.rightMargin: VLCStyle.margin_small

                    Widgets.SubtitleLabel {
                        text: providerModel.name
                        leftPadding: gridView.rowX

                        Layout.fillWidth: true
                    }

                    Widgets.TabButtonExt {
                        id: btn

                        focus: true
                        iconTxt: providerModel.indexed ? VLCIcons.remove : VLCIcons.add
                        text:  providerModel.indexed ?  i18n.qtr("Remove from medialibrary") : i18n.qtr("Add to medialibrary")
                        visible: !providerModel.is_on_provider_list && providerModel.canBeIndexed
                        onClicked: providerModel.indexed = !providerModel.indexed

                        Layout.preferredWidth: implicitWidth
                    }
                }

                Keys.onPressed: defaultKeyAction(event, 0)
                navigationParent: root
                navigationDown: function() {
                    focus = false
                    gridView.forceActiveFocus()
                }
            }

            cellWidth: VLCStyle.gridItem_network_width
            cellHeight: VLCStyle.gridCover_network_height + VLCStyle.margin_xsmall + VLCStyle.fontHeight_normal

            delegate: NetworkGridItem {
                id: delegateGrid

                property var model: ({})
                property int index: -1

                subtitle: ""
                height: VLCStyle.gridCover_network_height + VLCStyle.margin_xsmall + VLCStyle.fontHeight_normal

                onPlayClicked: selectionModel.model.addAndPlay( index )
                onItemClicked : {
                    selectionModel.updateSelection( modifier ,  view.currentItem.currentIndex, index)
                    view.currentItem.currentIndex = index
                    delegateGrid.forceActiveFocus()
                }

                onItemDoubleClicked: {
                    if (model.type === NetworkMediaModel.TYPE_NODE || model.type === NetworkMediaModel.TYPE_DIRECTORY)
                        history.push( ["mc", "network", { tree: model.tree } ])
                    else
                        selectionModel.model.addAndPlay( index )
                }

                onContextMenuButtonClicked: {
                    contextMenu.model = providerModel
                    contextMenu.selectionModel = selectionModel
                    contextMenu.popup()
                }
            }

            onSelectAll: selectionModel.selectAll()
            onSelectionUpdated: selectionModel.updateSelection( keyModifiers, oldIndex, newIndex )
            onActionAtIndex: _actionAtIndex(index)

            navigationParent: root
            navigationUpItem: gridView.headerItem
            navigationCancel: function() {
                history.previous()
            }
        }
    }

    Component{
        id: tableComponent

        Widgets.KeyNavigableTableView {
            id: tableView

            readonly property int _nbCols: VLCStyle.gridColumnsForWidth(tableView.availableRowWidth)
            readonly property int _nameColSpan: Math.max((_nbCols - 1) / 2, 1)
            property Component thumbnailHeader: Item {
                Widgets.IconLabel {
                    height: VLCStyle.listAlbumCover_height
                    width: VLCStyle.listAlbumCover_width
                    horizontalAlignment: Text.AlignHCenter
                    text: VLCIcons.album_cover
                    color: VLCStyle.colors.caption
                }
            }

            property Component thumbnailColumn: Item {
                id: item

                property var rowModel: parent.rowModel
                property var model: parent.colModel
                readonly property bool currentlyFocused: parent.currentlyFocused
                readonly property bool containsMouse: parent.containsMouse
                readonly property int index: parent.index

                Rectangle {
                    id: background

                    color: VLCStyle.colors.bg
                    width: VLCStyle.listAlbumCover_width
                    height: VLCStyle.listAlbumCover_height
                    visible: !artwork.visible

                    Image {
                        id: custom_cover

                        anchors.centerIn: parent
                        sourceSize.height: VLCStyle.icon_small
                        sourceSize.width: VLCStyle.icon_small
                        fillMode: Image.PreserveAspectFit
                        mipmap: true
                        source: {
                            switch (rowModel.type){
                            case NetworkMediaModel.TYPE_DISC:
                                return  "qrc:///type/disc.svg"
                            case NetworkMediaModel.TYPE_CARD:
                                return  "qrc:///type/capture-card.svg"
                            case NetworkMediaModel.TYPE_STREAM:
                                return  "qrc:///type/stream.svg"
                            case NetworkMediaModel.TYPE_PLAYLIST:
                                return  "qrc:///type/playlist.svg"
                            case NetworkMediaModel.TYPE_FILE:
                                return  "qrc:///type/file_black.svg"
                            default:
                                return "qrc:///type/directory_black.svg"
                            }
                        }
                    }

                    ColorOverlay {
                        anchors.fill: custom_cover
                        source: custom_cover
                        color: VLCStyle.colors.text
                        visible: rowModel.type !== NetworkMediaModel.TYPE_DISC
                                 && rowModel.type !== NetworkMediaModel.TYPE_CARD
                                 && rowModel.type !== NetworkMediaModel.TYPE_STREAM
                    }
                }

                Image {
                    id: artwork

                    x: (width - paintedWidth) / 2
                    y: (height - paintedHeight) / 2
                    width: VLCStyle.listAlbumCover_width
                    height: VLCStyle.listAlbumCover_height
                    fillMode: Image.PreserveAspectFit
                    horizontalAlignment: Image.AlignLeft
                    verticalAlignment: Image.AlignTop
                    source: item.rowModel.artwork
                    visible: item.rowModel.artwork && item.rowModel.artwork.toString() !== ""
                    mipmap: true
                }

                Widgets.PlayCover {
                    x: artwork.visible ? artwork.x : background.x
                    y: artwork.visible ? artwork.y : background.y
                    width: artwork.visible ? artwork.paintedWidth : background.width
                    height: artwork.visible ? artwork.paintedHeight : background.height
                    iconSize: VLCStyle.play_cover_small
                    visible: currentlyFocused || containsMouse
                    onIconClicked: providerModel.addAndPlay(item.index)
                    onlyBorders: rowModel.type === NetworkMediaModel.TYPE_NODE || rowModel.type === NetworkMediaModel.TYPE_DIRECTORY
                }
            }

            height: view.height
            width: view.width
            model: providerModel
            selectionDelegateModel: selectionModel
            focus: true
            headerColor: VLCStyle.colors.bg
            navigationParent: root
            navigationUpItem: tableView.headerItem
            navigationCancel: function() {
                history.previous()
            }

            rowHeight: VLCStyle.listAlbumCover_height + VLCStyle.margin_xxsmall * 2

            header: Widgets.NavigableFocusScope {
                width: view.width
                height: layout.implicitHeight + VLCStyle.margin_large + VLCStyle.margin_small
                navigable: btn.visible

                RowLayout {
                    id: layout

                    anchors.fill: parent
                    anchors.topMargin: VLCStyle.margin_large
                    anchors.bottomMargin: VLCStyle.margin_small
                    anchors.rightMargin: VLCStyle.margin_small

                    Widgets.SubtitleLabel {
                        text: providerModel.name
                        leftPadding: VLCStyle.margin_large

                        Layout.fillWidth: true
                    }

                    Widgets.TabButtonExt {
                        id: btn

                        focus: true
                        iconTxt: providerModel.indexed ? VLCIcons.remove : VLCIcons.add
                        text:  providerModel.indexed ?  i18n.qtr("Remove from medialibrary") : i18n.qtr("Add to medialibrary")
                        visible: !providerModel.is_on_provider_list && providerModel.canBeIndexed
                        onClicked: providerModel.indexed = !providerModel.indexed

                        Layout.preferredWidth: implicitWidth
                    }
                }

                Keys.onPressed: defaultKeyAction(event, 0)
                navigationParent: root
                navigationUpItem: root.navigationUpItem
                navigationDown: function() {
                    focus = false
                    tableView.forceActiveFocus()
                }
            }

            sortModel: [
                { criteria: "thumbnail", width: VLCStyle.colWidth(1), headerDelegate: tableView.thumbnailHeader, colDelegate: tableView.thumbnailColumn },
                { isPrimary: true, criteria: "name", width: VLCStyle.colWidth(tableView._nameColSpan), text: i18n.qtr("Name") },
                { criteria: "mrl", width: VLCStyle.colWidth(Math.max(tableView._nbCols - tableView._nameColSpan - 1), 1), text: i18n.qtr("Url"), showContextButton: true },
            ]

            onActionForSelection: _actionAtIndex(selection[0].row)
            onItemDoubleClicked: {
                if (model.type === NetworkMediaModel.TYPE_NODE || model.type === NetworkMediaModel.TYPE_DIRECTORY)
                    history.push( ["mc", "network", { tree: model.tree } ])
                else
                    providerModel.addAndPlay( index )
            }
            onContextMenuButtonClicked: {
                contextMenu.model = providerModel
                contextMenu.selectionModel = selectionModel
                contextMenu.popup(menuParent)
            }
        }
    }

    Widgets.StackViewExt {
        id: view
        anchors.fill:parent
        clip: true
        focus: true
        initialItem: medialib.gridView ? gridComponent : tableComponent

        Connections {
            target: medialib
            onGridViewChanged: {
                if (medialib.gridView)
                    view.replace(gridComponent)
                else
                    view.replace(tableComponent)
            }
        }

        Widgets.BusyIndicatorExt {
            runningDelayed: providerModel.parsingPending
            anchors.centerIn: parent
            z: 1
        }
    }
}
