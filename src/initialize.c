#include<stdlib.h>
#include<string.h>
#include"file.h"
#include"map.h"
void initialize(char* filename, MapList* map_list){
    if(map_list == NULL){
        printf("InitError:The map list pointer is NULL\n");
        return;
    } else if(filename == NULL||strlen(filename)==0){
        printf("InitError:The filename is empty\n");
        return;
    } else {
        Map *map_header = (Map *) malloc(sizeof(Map));
        map_list->mapheader = map_header;
        map_header->map = NULL;
        map_header->next = NULL;
        map_list->height = heightCount(filename);
        map_list->length = lengthCount(filename);
        printf("length = %d ", map_list->length);
        printf("height = %d\n", map_list->height);
        addMap(map_list, loadMapArray(filename, map_list));
    }
}