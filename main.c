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
    MapList* map_list = (MapList*)malloc(sizeof(MapList));
    //printf("%ld", sizeof(MapList));
    //
    initialize(argv[2], map_list);
    Map* this = map_list->mapheader;
    while(this->next!=NULL){
            this = this->next;
    }
    FILE* file = fopen(argv[3],"w");
    for(int i = 0;i<map_list->height;i++){
        for(int j = 0;j<map_list->length;j++){
            fprintf(file,"%d,", this->map[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
    int i;
    int num = atoi(argv[1]);
    for(i=0;i<num;i++) {
        computeMap(map_list, argv[3]);
    }
        //printf("%d", i);
//        Map* this = map_list->mapheader;
//        while(this->next!=NULL){
//            this = this->next;
//        }
    //printf("%d", i);
    //puts("123");
    return 0;
}



