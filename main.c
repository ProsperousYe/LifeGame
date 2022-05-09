#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "run.h"
#include "map.h"
#include "initialize.h"
int main(int argc, char* argv[]) {
    char com1[50] = "touch ";
    strcat(com1, argv[2]);
    char com2[50] = "touch ";
    strcat(com2, argv[3]);
    system(com1);
    system(com2);
    FILE* file = fopen(argv[3],"r");
    MapList* map_list = (MapList* )malloc(sizeof(MapList));
    initialize(file, map_list);
    //puts("123");
    int i;
    int num = atoi(argv[1]);
    for(i=0;i<num;i++){
        int** map = (int**)computeMap(map_list);
        addMap(map_list, map);
        //printf("%d", i);
    }
//    Map* this = map_list->mapheader;
//    while(this->next!=NULL){
//        this = this->next;
//    }
//    for(int i=0;i<map_list->height;i++){
//        for(int j=0; j<map_list->length;j++){
//            putc(this->map[i][j], file);
//        }
//        putc('\n',file);
//    }
    FILE* storefile = fopen(argv[3],"w");
    storeMapArray(storefile, map_list);
    return 0;
}



