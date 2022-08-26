//
// Created by vaca on 8/26/22.
//

#ifndef BT_SOURCE_DEMO_BT_SONG_H
#define BT_SOURCE_DEMO_BT_SONG_H


typedef void(*bt_scan_callback)(char* name);


void bt_init();
void bt_scan(bt_scan_callback callback);
void bt_connect(char * remote_name);
void bt_play_song(char* song_path);

#endif //BT_SOURCE_DEMO_BT_SONG_H
