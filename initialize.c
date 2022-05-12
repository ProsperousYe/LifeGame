#include<stdlib.h>
#include"file.h"
#include"map.h"
void initialize(char* filename, MapList* map_list){
    //puts("123");
    Map* map_header = (Map*)malloc(sizeof(Map));
    map_list->mapheader = map_header;
    map_header->map=NULL;
    map_header->next=NULL;
    //puts("123");
    map_list->height = heightCount(filename);
    //puts("123");
    map_list->length = lengthCount(filename);

    printf("length = %d ", map_list->length);
    printf("height = %d\n", map_list->height);
//    loadMapArray(filename, map_list);
    addMap(map_list,  loadMapArray(filename, map_list));
}