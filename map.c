#include "file.h"
#include <stdlib.h>
#include <stdio.h>
Map* createMapNode(int** map){
    Map* new_map = (Map*)malloc(sizeof(Map));
    new_map->map = map;
    new_map->next = NULL;
    return new_map;
}

void addMap(MapList* map_list, int** map){
    Map* this = map_list->mapheader;
    Map* new_map = createMapNode(map);
    new_map->map = map;
    new_map->next = NULL;
    while(this!=NULL){
        this=this->next;
    }
    this=new_map;
}
