//
// Created by sony on 22-5-8.
//

#ifndef MAIN_C_MAP_H
#define MAIN_C_MAP_H

typedef struct Map_{
    int** map;
    struct Map_* next;
}Map;

typedef struct MapList_{
    int height;
    int length;
    struct Map_* mapheader;
}MapList;

void addMap(MapList* map_list, int** map);
#endif //MAIN_C_MAP_H
