//
// Created by vaca on 8/26/22.
//

#ifndef BT_SOURCE_DEMO_BT_SONG_H
#define BT_SOURCE_DEMO_BT_SONG_H


typedef void(*bt_scan_callback)(char* name);
void bt_scan(bt_scan_callback callback);
void bt_init();
#endif //BT_SOURCE_DEMO_BT_SONG_H
