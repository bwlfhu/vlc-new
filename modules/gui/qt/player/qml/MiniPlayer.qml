import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import org.videolan.vlc 0.1

import "qrc:///widgets/" as Widgets
import "qrc:///util/KeyHelper.js" as KeyHelper
import "qrc:///style/"

Widgets.NavigableFocusScope {

    id: root

    readonly property bool expanded: root.implicitHeight === root.childrenRect.height

    property var mainContent: undefined

    Component.onCompleted: {
        if (player.playingState !== PlayerController.PLAYING_STATE_STOPPED)
            root.implicitHeight = Qt.binding(function() { return VLCStyle.miniPlayerHeight; })
    }

    Connections {
        target: player
        onPlayingStateChanged: {
            if (player.playingState === PlayerController.PLAYING_STATE_STOPPED)
                animateRetract.start()
            else if (player.playingState === PlayerController.PLAYING_STATE_PLAYING)
                animateExpand.start()
        }
    }

    PropertyAnimation {
        id: animateExpand;
        target: root;
        properties: "implicitHeight"
        duration: 200
        easing.type: Easing.InSine
        to: VLCStyle.miniPlayerHeight
        onStopped: {
            root.implicitHeight = Qt.binding(function() { return VLCStyle.miniPlayerHeight; })
        }
    }

    PropertyAnimation {
        id: animateRetract;
        target: root;
        properties: "implicitHeight"
        duration: 200
        easing.type: Easing.OutSine
        to: 0
        onStopped: {
            root.implicitHeight = 0
        }
    }

    // this MouseArea prevents mouse events to be sent below miniplayer
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.AllButtons
    }

    Column {
        anchors.left: parent.left
        anchors.right: parent.right

        spacing: VLCStyle.dp(-progressBar.height / 2, VLCStyle.scale)

        SliderBar {
            id: progressBar
            value: player.position
            visible: progressBar.value >= 0.0 && progressBar.value <= 1.0
            z: 1

            isMiniplayer: true

            anchors {
                left: parent.left
                right: parent.right
            }
        }


        Item {
            id: mainRect

            anchors {
                left: parent.left
                right: parent.right
            }
            z: 0
            height: VLCStyle.miniPlayerHeight

            Widgets.FrostedGlassEffect {
                anchors.fill: parent

                source: mainContent
                sourceRect: Qt.rect(root.x, root.y, root.width, root.height)

                tint: VLCStyle.colors.blendColors(VLCStyle.colors.bg, VLCStyle.colors.banner, 0.85)
            }

            RowLayout {
                anchors {
                    fill: parent

                    leftMargin: VLCStyle.applicationHorizontalMargin
                    rightMargin: VLCStyle.applicationHorizontalMargin
                    bottomMargin: VLCStyle.applicationVerticalMargin
                }

                spacing: VLCStyle.margin_normal

                Widgets.FocusBackground {
                    id: playingItemInfo
                    Layout.fillHeight: true
                    Layout.preferredWidth: playingItemInfoRow.implicitWidth
                    width: childrenRect.width
                    focus: true
                    Layout.leftMargin: VLCStyle.margin_normal

                    MouseArea {
                        anchors.fill: parent
                        onClicked: history.push(["player"])
                    }

                    Keys.onPressed: {
                        if (KeyHelper.matchOk(event) ) {
                            event.accepted = true
                        }
                    }
                    Keys.onReleased: {
                        if (!event.accepted && KeyHelper.matchOk(event))
                            history.push(["player"])
                    }


                    Row {
                        id: playingItemInfoRow
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom

                        Item {
                            anchors.verticalCenter: parent.verticalCenter
                            implicitHeight: childrenRect.height
                            implicitWidth:  childrenRect.width

                            Rectangle {
                                id: coverRect
                                anchors.fill: cover
                                color: VLCStyle.colors.bg
                            }

                            DropShadow {
                                anchors.fill: coverRect
                                source: coverRect
                                radius: 8
                                samples: 17
                                color: VLCStyle.colors.glowColorBanner
                                spread: 0.2
                            }

                            Image {
                                id: cover

                                source: (mainPlaylistController.currentItem.artwork && mainPlaylistController.currentItem.artwork.toString())
                                        ? mainPlaylistController.currentItem.artwork
                                        : VLCStyle.noArtAlbum
                                fillMode: Image.PreserveAspectFit

                                width: VLCStyle.dp(60, VLCStyle.scale)
                                height: VLCStyle.dp(60, VLCStyle.scale)
                            }
                        }

                        Column {
                            anchors.verticalCenter: parent.verticalCenter
                            leftPadding: VLCStyle.margin_xsmall

                            Widgets.MenuLabel {
                                id: titleLabel
                                text: mainPlaylistController.currentItem.title
                            }

                            Widgets.MenuCaption {
                                id: artistLabel
                                text: mainPlaylistController.currentItem.artist
                            }

                            Widgets.MenuCaption {
                                id: progressIndicator
                                text: player.time.toString() + " / " + player.length.toString()
                            }
                        }
                    }

                    KeyNavigation.right: buttonrow
                }

                Item {
                    Layout.fillWidth: true
                }

                PlayerButtonsLayout {
                    id: buttonrow

                    model: miniPlayerModel
                    defaultSize: VLCStyle.icon_normal

                    Layout.alignment: Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.preferredHeight: buttonrow.implicitHeight
                    Layout.leftMargin: VLCStyle.margin_normal
                    Layout.rightMargin: VLCStyle.margin_normal

                    navigationParent: root
                    navigationLeftItem: playingItemInfo
                }
            }

            Connections{
                target: mainInterface
                onToolBarConfUpdated: {
                    miniPlayerModel.reloadModel()
                }
            }

            PlayerControlBarModel {
                id: miniPlayerModel
                mainCtx: mainctx
                configName: "MiniPlayerToolbar"
            }

            ControlButtons {
                id: controlmodelbuttons

                isMiniplayer: true
                parentWindow: mainInterfaceRect
            }

            Keys.onPressed: {
                if (!event.accepted)
                    defaultKeyAction(event, 0)
                if (!event.accepted)
                    mainInterface.sendHotkey(event.key, event.modifiers);
            }
        }
    }
}
