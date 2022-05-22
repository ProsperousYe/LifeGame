//
// Created by sony on 22-5-7. test module
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../src/file.h"
#include "../src/run.h"
#include "../src/map.h"
#include "../src/initialize.h"
#include "../src/sdl.h"

void testCompute(MapList* maplist, char* filename, int** com){
    computeMap(maplist, filename);
    int** ret = loadMapArray(filename, maplist);
    for(int i = 0;i<maplist->height;i++){
        for(int j = 0;j<maplist->length;j++){
            if(ret[i][j] != com[i][j]){
                printf("----------------------------------------------\n");
                printf("| ComputeError:The compute process is wrong! |\n");
                printf("----------------------------------------------\n");
            }
        }
    }
    printf("------------------------------------\n");
    printf("| computeMap() function test pass! |\n");
    printf("------------------------------------\n");
}

int main(int argc, char* argv[]){
    //create test1 file
    system("mkdir test");
    system("touch test/test/test1.txt");
    FILE* test1= fopen("test/test/test1.txt", "w");
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            fprintf(test1, "%d", 0);
        }
        fprintf(test1, "\n");
    }
    fclose(test1);
    //creat test2 file[normal one]
    system("touch test/test/test2.txt");
    FILE* test2 = fopen("test/test/test2.txt", "w");
    for(int i = 0;i<5;i++){
        for(int i = 0;i<5;i++){
            fprintf(test2, "%d,", 0);
        }
        fprintf(test2, "\n");
    }
    fclose(test2);
    //create test3 file
    system("touch test/test/test3.txt");
    //begin test
    if(lengthCount("test/test/test1.txt")<0||lengthCount("test/test2.txt")>0||lengthCount("test/test3.txt")<0){
        printf("-----------------------------\n");
        printf("| lengthCount() test passed |\n");
        printf("-----------------------------\n");
    } else {
        printf("-----------------------------\n");
        printf("| lengthCount() test failed |\n");
        printf("-----------------------------\n");
    }
    if(heightCount("test/test/test2.txt")>0||lengthCount("test/test3.txt")<0){
        printf("-----------------------------\n");
        printf("| heightCount() test passed |\n");
        printf("-----------------------------\n");
    } else {
        printf("-----------------------------\n");
        printf("| heightCount() test failed |\n");
        printf("-----------------------------\n");
    }
    //puts("123");
    int** test_map = NULL;
    MapList* test_list = NULL;
    initialize("test/test/test1.txt", test_list);
    loadMapArray("test/test/test1.txt", test_list);
    addMap(test_list, test_map);
    test_map = (int**)malloc(5*sizeof(int));
    int** com = (int**)malloc(5*sizeof(int));
    for(int i= 0;i<5;i++){
        com[i] = (int*)malloc(5*sizeof(int));
        test_map[i] = (int*)malloc(5*sizeof(int));
        for(int j=0;j<5;j++){
            com[i][j] = 0;
            test_map[i][j] = 0;
        }
    }

    test_list = (MapList*)malloc(sizeof(MapList));
    Map* header = (Map*)malloc(sizeof(Map));
    Map* testnode = (Map*)malloc(sizeof(Map));
    test_list->mapheader = header;
    header->map = NULL;
    header->next = testnode;
    testnode->map = test_map;
    testnode->next = NULL;
    test_list->height=5;
    test_list->length=5;
    com[1][1]=1;
    com[2][2]=1;com[2][3]=1;
    com[3][1]=1;com[3][2]=1;
    test_map[1][2]=1;
    test_map[2][0]=1;test_map[2][2]=1;
    test_map[3][1]=1;test_map[3][2]=1;
    FILE* test_2 = fopen("test/test/test2.txt","w");
    for(int i= 0;i<5;i++){
        for(int j=0;j<5;j++){
            fprintf(test_2, "%d,",test_map[i][j]);
        }
        fprintf(test_2, "\n");
    }
    fclose(test_2);
    testCompute(test_list, "test/test/test2.txt", com);
}