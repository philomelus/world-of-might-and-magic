#pragma once
#include "GUI/GUIWindow.h"

void GameUI_WritePointedObjectStatusString();
void GameUI_OnPlayerPortraitLeftClick(unsigned int uPlayerID); // idb

__int16 sub_441A4E(int a1);



struct GUIWindow_GameMenu : public GUIWindow
{
             GUIWindow_GameMenu();
    virtual ~GUIWindow_GameMenu() {}

    virtual void Update();
};



struct GUIWindow_GameOptions : public GUIWindow
{
             GUIWindow_GameOptions();
    virtual ~GUIWindow_GameOptions() {}

    virtual void Update();
};



struct GUIWindow_GameKeyBindings : public GUIWindow
{
             GUIWindow_GameKeyBindings();
    virtual ~GUIWindow_GameKeyBindings() {}

    virtual void Update();
};



struct GUIWindow_GameVideoOptions : public GUIWindow
{
             GUIWindow_GameVideoOptions();
    virtual ~GUIWindow_GameVideoOptions() {}

    virtual void Update();
};




extern class Image *game_ui_statusbar;
extern class Image *game_ui_rightframe;
extern class Image *game_ui_topframe;
extern class Image *game_ui_leftframe;
extern class Image *game_ui_bottomframe;

extern class Image *game_ui_monster_hp_green;
extern class Image *game_ui_monster_hp_yellow;
extern class Image *game_ui_monster_hp_red;
extern class Image *game_ui_monster_hp_background;
extern class Image *game_ui_monster_hp_border_left;
extern class Image *game_ui_monster_hp_border_right;

extern class Image *game_ui_minimap_frame;   // 5079D8
extern class Image *game_ui_minimap_compass; // 5079B4
extern std::array<class Image *, 8> game_ui_minimap_dirs;

extern class Image *game_ui_menu_quit;
extern class Image *game_ui_menu_resume;
extern class Image *game_ui_menu_controls;
extern class Image *game_ui_menu_save;
extern class Image *game_ui_menu_load;
extern class Image *game_ui_menu_new;
extern class Image *game_ui_menu_options;

extern class Image *game_ui_tome_storyline;
extern class Image *game_ui_tome_calendar;
extern class Image *game_ui_tome_maps;
extern class Image *game_ui_tome_autonotes;
extern class Image *game_ui_tome_quests;

extern class Image *game_ui_btn_rest;
extern class Image *game_ui_btn_cast;
extern class Image *game_ui_btn_zoomin;
extern class Image *game_ui_btn_zoomout;
extern class Image *game_ui_btn_quickref;
extern class Image *game_ui_btn_settings;

extern class Image *game_ui_dialogue_background;

extern std::array<class Image *, 5> game_ui_options_controls;

extern class Image *game_ui_evtnpc; // 50795C


extern std::array< std::array<class Image *, 56>, 4> game_ui_player_faces;
extern class Image *game_ui_player_face_eradicated;
extern class Image *game_ui_player_face_dead;

extern class Image *game_ui_player_selection_frame; // 50C98C
extern class Image *game_ui_player_alert_yellow; // 5079C8
extern class Image *game_ui_player_alert_red;    // 5079CC
extern class Image *game_ui_player_alert_green;  // 5079D0

extern class Image *game_ui_bar_red;
extern class Image *game_ui_bar_yellow;
extern class Image *game_ui_bar_green;
extern class Image *game_ui_bar_blue;

extern class Image *game_ui_playerbuff_pain_reflection;
extern class Image *game_ui_playerbuff_hammerhands;
extern class Image *game_ui_playerbuff_preservation;
extern class Image *game_ui_playerbuff_bless;