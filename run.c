#include <stdlib.h>
#include "map.h"
int** copyArray(MapList* mapList, int** old_map){
    int **new_map = (int**)malloc(mapList->height*mapList->length*sizeof(int));
    int i;
    for(i = 0; i<mapList->height; i++){
        int j;
        for(j = 0;j<mapList->length;j++){
            new_map[i][j] = old_map[i][j];
        }
    }
    return new_map;
}

int** computeMap(MapList* maplist){
    Map* this = maplist->mapheader;
    while(this->next=NULL){
        this = this->next;
    }
    int** map_after = copyArray(maplist, this->map);
    int** map_before = this->map;
    int i;
    int env;
    for(i=0;i<maplist->height;i++){
        int j;
        for(j=0;j<maplist->length;j++){
            env = map_before[i-1][j-1]+map_before[i-1][j]+map_before[i-1][j+1]
                  +map_before[i][j-1]+map_before[i][j+1]
                  +map_before[i+1][j-1]+map_before[i+1][j]+map_before[i+1][j+1];
            if(map_before[i][j]==1){
                if(env == 2 || env == 3){
                map_after[i][j]=1;
                } else {
                map_after[i][j]=0;
                }
            } else {
                if(env == 3){
                    map_after[i][j] = 1;
                } else {
                    map_after[i][j] = 0;
                }
            }
        }
    }
    return map_after;
}