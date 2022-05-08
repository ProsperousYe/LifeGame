#include<stdlib.h>
#include"file.h"
#include"map.h"
void initialize(FILE* file, MapList* map_list){
    Map* map_header = (Map*)malloc(sizeof(Map));
    map_list->mapheader = map_header;
    map_header->map=NULL;
    map_header->next=NULL;
    loadMapArray(file, map_list);
    map_list->height= heightCount(file);
    map_list->length= lengthCount(file);
}