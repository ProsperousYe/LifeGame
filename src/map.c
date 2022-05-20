#include "file.h"
#include <stdlib.h>
#include <stdio.h>
void addMap(MapList* map_list, int** map){

    if(map==NULL||map_list==NULL){
        printf("AddMapError:the map list pointer or map pointer is NULL\n");
    } else {
        puts("enter add");
        Map* this = map_list->mapheader;
        while(this->next!=NULL){
            this=this->next;
        }
        Map* new_map = (Map*)malloc(sizeof(Map));
        this->next = new_map;
        new_map->map = map;
        new_map->next = NULL;
        //printf("\nadd:\n");
//        for(int i = 0;i<map_list->height;i++){
//            for(int j = 0;j<map_list->length;j++){
//                printf("%d,", map[i][j]);
//            }
//            printf("\n");
//        }
        puts("exit add");
    }
}
