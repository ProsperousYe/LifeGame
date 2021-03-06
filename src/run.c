#include <stdio.h>
#include "map.h"
#include "file.h"
void computeMap(MapList* maplist, char* filename){
    puts("enter computeMap");
    Map* this = maplist->mapheader;
    while(this->next!=NULL){
        this = this->next;
    }
    int** map_before = this->map;
//    for(int i = 0;i<maplist->height;i++){
//        for(int j = 0;j<maplist->length;j++){
//            printf("%d,", map_before[i][j]);
//        }
//        printf("\n");
//    }
    int i;
    int env;
    FILE* file = fopen(filename,"w");
    for(i=0;i<maplist->height;i++){
        int j;
        for(j=0;j<maplist->length;j++){
            if(i>0&&j>0&&i<maplist->height-1&&j<maplist->length-1) {
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i - 1][j + 1]
                      + map_before[i][j - 1] + map_before[i][j + 1]
                      + map_before[i + 1][j - 1] + map_before[i + 1][j] + map_before[i + 1][j + 1];
            } else if(i==0&&j>0&&j<maplist->length-1){
                env =  map_before[i][j - 1] + map_before[i][j + 1] + map_before[i + 1][j - 1]
                        + map_before[i + 1][j] + map_before[i + 1][j + 1];
            } else if(i==maplist->height-1&&j>0&&j<maplist->length-1){
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i - 1][j + 1]
                      + map_before[i][j - 1] + map_before[i][j + 1];
            } else if(j==0&&i>0&&i<maplist->height-1){
                env =  map_before[i - 1][j] + map_before[i - 1][j + 1] + map_before[i][j + 1]
                        + map_before[i + 1][j] + map_before[i + 1][j + 1];
            } else if(j==maplist->length-1&&i>0&&i<maplist->height-1){
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i][j - 1]
                      + map_before[i + 1][j - 1] + map_before[i + 1][j];
            } else if(i==0&&j==0){
                env =  map_before[i][j + 1] + map_before[i + 1][j] + map_before[i + 1][j + 1];
                //puts("123");
            } else if(i==maplist->height-1&&j==0){
                env =  map_before[i - 1][j] + map_before[i - 1][j + 1] + map_before[i][j + 1];
            } else if(i==0&&j==maplist->length-1){
                env =  map_before[i][j - 1] + map_before[i + 1][j - 1] + map_before[i + 1][j];
            } else if(i==maplist->height-1&&j==maplist->length-1){
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i][j - 1];
            }
            //puts("123");
            if(map_before[i][j]==1){
                //printf("life: 1, env: %d = ",env);
                if(env == 2 || env == 3){
                    fprintf(file,"%d,",1);
                    //printf(" %d,", 1);
                } else {
                    fprintf(file,"%d,",0);
                    //printf(" %d,", 0);
                }
            } else {
                //printf("life: 0, env: %d = ",env);
                if(env == 3){
                    fprintf(file,"%d,",1);
                    //printf(" %d,", 1);
                } else {
                    fprintf(file,"%d,",0);
                    //printf(" %d,", 0);
                }
            }
        }
        fprintf(file,"\n");
         //printf("\n");
    }
    fclose(file);
    puts("exit computeMap");
}

void computeGrids(int** map_before, char* filename, int length, int height){
    puts("enter computeMap");
    int i;
    int env;
    FILE* file = fopen(filename,"w");
    for(i=0;i<height;i++){
        int j;
        for(j=0;j<length;j++){
            if(i>0&&j>0&&i<height-1&&j<length-1) {
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i - 1][j + 1]
                      + map_before[i][j - 1] + map_before[i][j + 1]
                      + map_before[i + 1][j - 1] + map_before[i + 1][j] + map_before[i + 1][j + 1];
            } else if(i==0&&j>0&&j<length-1){
                env =  map_before[i][j - 1] + map_before[i][j + 1] + map_before[i + 1][j - 1]
                       + map_before[i + 1][j] + map_before[i + 1][j + 1];
            } else if(i==height-1&&j>0&&j<length-1){
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i - 1][j + 1]
                      + map_before[i][j - 1] + map_before[i][j + 1];
            } else if(j==0&&i>0&&i<height-1){
                env =  map_before[i - 1][j] + map_before[i - 1][j + 1] + map_before[i][j + 1]
                       + map_before[i + 1][j] + map_before[i + 1][j + 1];
            } else if(j==length-1&&i>0&&i<height-1){
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i][j - 1]
                      + map_before[i + 1][j - 1] + map_before[i + 1][j];
            } else if(i==0&&j==0){
                env =  map_before[i][j + 1] + map_before[i + 1][j] + map_before[i + 1][j + 1];
                //puts("123");
            } else if(i==height-1&&j==0){
                env =  map_before[i - 1][j] + map_before[i - 1][j + 1] + map_before[i][j + 1];
            } else if(i==0&&j==length-1){
                env =  map_before[i][j - 1] + map_before[i + 1][j - 1] + map_before[i + 1][j];
            } else if(i==height-1&&j==length-1){
                env = map_before[i - 1][j - 1] + map_before[i - 1][j] + map_before[i][j - 1];
            }
            if(map_before[i][j]==1){
                if(env == 2 || env == 3){
                    fprintf(file,"%d,",1);
                } else {
                    fprintf(file,"%d,",0);
                }
            } else {
                if(env == 3){
                    fprintf(file,"%d,",1);
                } else {
                    fprintf(file,"%d,",0);
                }
            }
        }
        fprintf(file,"\n");
    }
    fclose(file);
    puts("exit computeMap");
}

