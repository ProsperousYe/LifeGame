//
// Created by sony on 22-5-8.
//
#include <stdio.h>
#include "map.h"
#ifndef MAIN_C_FILE_H
#define MAIN_C_FILE_H
int lengthCount(char* filename);

int heightCount(char* filename);

int* loadMapArray(char* filename, MapList* maplist);

void storeMapArray(FILE* file, MapList* maplist);
#endif //MAIN_C_FILE_H
