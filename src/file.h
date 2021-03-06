//
// Created by sony on 22-5-8.
//
#include <stdio.h>
#include "map.h"
#ifndef MAIN_C_FILE_H
#define MAIN_C_FILE_H
int lengthCount(char* filename);

int heightCount(char* filename);

int** loadMapArray(char* filename,MapList* map_list);

void storeMapArray(FILE* file, MapList* maplist);

int** readMap(char* filename,int** map, int length, int height);
#endif //MAIN_C_FILE_H
