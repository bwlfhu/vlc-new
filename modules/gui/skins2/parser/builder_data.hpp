/*****************************************************************************
 * builder_data.hpp
 *****************************************************************************
 * Copyright (C) 2003 the VideoLAN team
 *
 * Authors: Cyril Deguet     <asmax@via.ecp.fr>
 *          Olivier Teuliere <ipkiss@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

//File generated by gen_builder.py
//DO NOT EDIT BY HAND !

#ifndef BUILDER_DATA_HPP
#define BUILDER_DATA_HPP

#include <vlc_common.h>
#include <list>
#include <map>
#include <string>

/// Structure for mapping data from XML file
struct BuilderData
{

    /// Type definition
    struct Theme
    {
        Theme( const std::string & tooltipfont, int magnet, uint32_t alpha, uint32_t moveAlpha ):
m_tooltipfont( tooltipfont ), m_magnet( magnet ), m_alpha( alpha ), m_moveAlpha( moveAlpha ) {}

        std::string m_tooltipfont;
        int m_magnet;
        uint32_t m_alpha;
        uint32_t m_moveAlpha;
    };
    /// List
    std::list<Theme> m_listTheme;

    /// Type definition
    struct Bitmap
    {
        Bitmap( const std::string & id, const std::string & fileName, uint32_t alphaColor, int nbFrames, int fps, int nbLoops ):
m_id( id ), m_fileName( fileName ), m_alphaColor( alphaColor ), m_nbFrames( nbFrames ), m_fps( fps ), m_nbLoops( nbLoops ) {}

        std::string m_id;
        std::string m_fileName;
        uint32_t m_alphaColor;
        int m_nbFrames;
        int m_fps;
        int m_nbLoops;
    };
    /// List
    std::list<Bitmap> m_listBitmap;

    /// Type definition
    struct SubBitmap
    {
        SubBitmap( const std::string & id, const std::string & parent, int x, int y, int width, int height, int nbFrames, int fps, int nbLoops ):
m_id( id ), m_parent( parent ), m_x( x ), m_y( y ), m_width( width ), m_height( height ), m_nbFrames( nbFrames ), m_fps( fps ), m_nbLoops( nbLoops ) {}

        std::string m_id;
        std::string m_parent;
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        int m_nbFrames;
        int m_fps;
        int m_nbLoops;
    };
    /// List
    std::list<SubBitmap> m_listSubBitmap;

    /// Type definition
    struct BitmapFont
    {
        BitmapFont( const std::string & id, const std::string & file, const std::string & type ):
m_id( id ), m_file( file ), m_type( type ) {}

        std::string m_id;
        std::string m_file;
        std::string m_type;
    };
    /// List
    std::list<BitmapFont> m_listBitmapFont;

    /// Type definition
    struct Font
    {
        Font( const std::string & id, const std::string & fontFile, int size ):
m_id( id ), m_fontFile( fontFile ), m_size( size ) {}

        std::string m_id;
        std::string m_fontFile;
        int m_size;
    };
    /// List
    std::list<Font> m_listFont;

    /// Type definition
    struct PopupMenu
    {
        PopupMenu( const std::string & id ):
m_id( id ) {}

        std::string m_id;
    };
    /// List
    std::list<PopupMenu> m_listPopupMenu;

    /// Type definition
    struct MenuItem
    {
        MenuItem( const std::string & label, const std::string & action, int pos, const std::string & popupId ):
m_label( label ), m_action( action ), m_pos( pos ), m_popupId( popupId ) {}

        std::string m_label;
        std::string m_action;
        int m_pos;
        std::string m_popupId;
    };
    /// List
    std::list<MenuItem> m_listMenuItem;

    /// Type definition
    struct MenuSeparator
    {
        MenuSeparator( int pos, const std::string & popupId ):
m_pos( pos ), m_popupId( popupId ) {}

        int m_pos;
        std::string m_popupId;
    };
    /// List
    std::list<MenuSeparator> m_listMenuSeparator;

    /// Type definition
    struct Window
    {
        Window( const std::string & id, int xPos, int yPos, const std::string & position, const std::string & xOffset, const std::string & yOffset, const std::string & xMargin, const std::string & yMargin, bool visible, bool dragDrop, bool playOnDrop ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_position( position ), m_xOffset( xOffset ), m_yOffset( yOffset ), m_xMargin( xMargin ), m_yMargin( yMargin ), m_visible( visible ), m_dragDrop( dragDrop ), m_playOnDrop( playOnDrop ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_position;
        std::string m_xOffset;
        std::string m_yOffset;
        std::string m_xMargin;
        std::string m_yMargin;
        bool m_visible;
        bool m_dragDrop;
        bool m_playOnDrop;
    };
    /// List
    std::list<Window> m_listWindow;

    /// Type definition
    struct Layout
    {
        Layout( const std::string & id, int width, int height, int minWidth, int maxWidth, int minHeight, int maxHeight, const std::string & windowId ):
m_id( id ), m_width( width ), m_height( height ), m_minWidth( minWidth ), m_maxWidth( maxWidth ), m_minHeight( minHeight ), m_maxHeight( maxHeight ), m_windowId( windowId ) {}

        std::string m_id;
        int m_width;
        int m_height;
        int m_minWidth;
        int m_maxWidth;
        int m_minHeight;
        int m_maxHeight;
        std::string m_windowId;
    };
    /// List
    std::list<Layout> m_listLayout;

    /// Type definition
    struct Anchor
    {
        Anchor( int xPos, int yPos, const std::string & leftTop, int range, int priority, const std::string & points, const std::string & layoutId ):
m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_range( range ), m_priority( priority ), m_points( points ), m_layoutId( layoutId ) {}

        int m_xPos;
        int m_yPos;
        std::string m_leftTop;
        int m_range;
        int m_priority;
        std::string m_points;
        std::string m_layoutId;
    };
    /// List
    std::list<Anchor> m_listAnchor;

    /// Type definition
    struct Button
    {
        Button( const std::string & id, int xPos, int yPos, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & visible, const std::string & upId, const std::string & downId, const std::string & overId, const std::string & actionId, const std::string & tooltip, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_upId( upId ), m_downId( downId ), m_overId( overId ), m_actionId( actionId ), m_tooltip( tooltip ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_visible;
        std::string m_upId;
        std::string m_downId;
        std::string m_overId;
        std::string m_actionId;
        std::string m_tooltip;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Button> m_listButton;

    /// Type definition
    struct Checkbox
    {
        Checkbox( const std::string & id, int xPos, int yPos, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & visible, const std::string & up1Id, const std::string & down1Id, const std::string & over1Id, const std::string & up2Id, const std::string & down2Id, const std::string & over2Id, const std::string & state, const std::string & action1, const std::string & action2, const std::string & tooltip1, const std::string & tooltip2, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_up1Id( up1Id ), m_down1Id( down1Id ), m_over1Id( over1Id ), m_up2Id( up2Id ), m_down2Id( down2Id ), m_over2Id( over2Id ), m_state( state ), m_action1( action1 ), m_action2( action2 ), m_tooltip1( tooltip1 ), m_tooltip2( tooltip2 ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_visible;
        std::string m_up1Id;
        std::string m_down1Id;
        std::string m_over1Id;
        std::string m_up2Id;
        std::string m_down2Id;
        std::string m_over2Id;
        std::string m_state;
        std::string m_action1;
        std::string m_action2;
        std::string m_tooltip1;
        std::string m_tooltip2;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Checkbox> m_listCheckbox;

    /// Type definition
    struct Image
    {
        Image( const std::string & id, int xPos, int yPos, int width, int height, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & visible, const std::string & bmpId, const std::string & actionId, const std::string & action2Id, const std::string & resize, const std::string & help, bool art, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_bmpId( bmpId ), m_actionId( actionId ), m_action2Id( action2Id ), m_resize( resize ), m_help( help ), m_art( art ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_visible;
        std::string m_bmpId;
        std::string m_actionId;
        std::string m_action2Id;
        std::string m_resize;
        std::string m_help;
        bool m_art;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Image> m_listImage;

    /// Type definition
    struct IniFile
    {
        IniFile( const std::string & id, const std::string & file ):
m_id( id ), m_file( file ) {}

        std::string m_id;
        std::string m_file;
    };
    /// List
    std::list<IniFile> m_listIniFile;

    /// Type definition
    struct Panel
    {
        Panel( const std::string & id, int xPos, int yPos, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, int width, int height, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_width( width ), m_height( height ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        int m_width;
        int m_height;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Panel> m_listPanel;

    /// Type definition
    struct Text
    {
        Text( const std::string & id, int xPos, int yPos, const std::string & visible, const std::string & fontId, const std::string & text, int width, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, uint32_t color, const std::string & scrolling, const std::string & alignment, const std::string & focus, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_visible( visible ), m_fontId( fontId ), m_text( text ), m_width( width ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_color( color ), m_scrolling( scrolling ), m_alignment( alignment ), m_focus( focus ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_visible;
        std::string m_fontId;
        std::string m_text;
        int m_width;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        uint32_t m_color;
        std::string m_scrolling;
        std::string m_alignment;
        std::string m_focus;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Text> m_listText;

    /// Type definition
    struct RadialSlider
    {
        RadialSlider( const std::string & id, const std::string & visible, int xPos, int yPos, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & sequence, int nbImages, float minAngle, float maxAngle, const std::string & value, const std::string & tooltip, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_visible( visible ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_sequence( sequence ), m_nbImages( nbImages ), m_minAngle( minAngle ), m_maxAngle( maxAngle ), m_value( value ), m_tooltip( tooltip ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        std::string m_visible;
        int m_xPos;
        int m_yPos;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_sequence;
        int m_nbImages;
        float m_minAngle;
        float m_maxAngle;
        std::string m_value;
        std::string m_tooltip;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<RadialSlider> m_listRadialSlider;

    /// Type definition
    struct Slider
    {
        Slider( const std::string & id, const std::string & visible, int xPos, int yPos, int width, int height, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & upId, const std::string & downId, const std::string & overId, const std::string & points, int thickness, const std::string & value, const std::string & imageId, int nbHoriz, int nbVert, int padHoriz, int padVert, const std::string & tooltip, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_visible( visible ), m_xPos( xPos ), m_yPos( yPos ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_upId( upId ), m_downId( downId ), m_overId( overId ), m_points( points ), m_thickness( thickness ), m_value( value ), m_imageId( imageId ), m_nbHoriz( nbHoriz ), m_nbVert( nbVert ), m_padHoriz( padHoriz ), m_padVert( padVert ), m_tooltip( tooltip ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        std::string m_visible;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_upId;
        std::string m_downId;
        std::string m_overId;
        std::string m_points;
        int m_thickness;
        std::string m_value;
        std::string m_imageId;
        int m_nbHoriz;
        int m_nbVert;
        int m_padHoriz;
        int m_padVert;
        std::string m_tooltip;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Slider> m_listSlider;

    /// Type definition
    struct List
    {
        List( const std::string & id, int xPos, int yPos, const std::string & visible, int width, int height, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & fontId, const std::string & var, const std::string & bgImageId, const std::string & fgColor, const std::string & playColor, const std::string & bgColor1, const std::string & bgColor2, const std::string & selColor, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_visible( visible ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_fontId( fontId ), m_var( var ), m_bgImageId( bgImageId ), m_fgColor( fgColor ), m_playColor( playColor ), m_bgColor1( bgColor1 ), m_bgColor2( bgColor2 ), m_selColor( selColor ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_visible;
        int m_width;
        int m_height;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_fontId;
        std::string m_var;
        std::string m_bgImageId;
        std::string m_fgColor;
        std::string m_playColor;
        std::string m_bgColor1;
        std::string m_bgColor2;
        std::string m_selColor;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<List> m_listList;

    /// Type definition
    struct Tree
    {
        Tree( const std::string & id, int xPos, int yPos, const std::string & visible, const std::string & flat, int width, int height, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & fontId, const std::string & var, const std::string & bgImageId, const std::string & itemImageId, const std::string & openImageId, const std::string & closedImageId, const std::string & fgColor, const std::string & playColor, const std::string & bgColor1, const std::string & bgColor2, const std::string & selColor, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_visible( visible ), m_flat( flat ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_fontId( fontId ), m_var( var ), m_bgImageId( bgImageId ), m_itemImageId( itemImageId ), m_openImageId( openImageId ), m_closedImageId( closedImageId ), m_fgColor( fgColor ), m_playColor( playColor ), m_bgColor1( bgColor1 ), m_bgColor2( bgColor2 ), m_selColor( selColor ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        std::string m_visible;
        std::string m_flat;
        int m_width;
        int m_height;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_fontId;
        std::string m_var;
        std::string m_bgImageId;
        std::string m_itemImageId;
        std::string m_openImageId;
        std::string m_closedImageId;
        std::string m_fgColor;
        std::string m_playColor;
        std::string m_bgColor1;
        std::string m_bgColor2;
        std::string m_selColor;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Tree> m_listTree;

    /// Type definition
    struct Video
    {
        Video( const std::string & id, int xPos, int yPos, int width, int height, const std::string & leftTop, const std::string & rightBottom, bool xKeepRatio, bool yKeepRatio, const std::string & visible, bool autoResize, const std::string & help, int layer, const std::string & windowId, const std::string & layoutId, const std::string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_autoResize( autoResize ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        std::string m_id;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
        std::string m_leftTop;
        std::string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        std::string m_visible;
        bool m_autoResize;
        std::string m_help;
        int m_layer;
        std::string m_windowId;
        std::string m_layoutId;
        std::string m_panelId;
    };
    /// List
    std::list<Video> m_listVideo;


};

#endif
