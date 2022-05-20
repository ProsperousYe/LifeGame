//
// Created by sony on 22-5-11.
//

#ifndef MAIN_C_SDL_H
#define MAIN_C_SDL_H
#include "map.h"
//void showInit(void);
void drawGrids(MapList* maplist, char* filename,SDL_Window* window, SDL_Surface* screenSurface);
void chooseGrids(SDL_Surface* surface, SDL_Window* window, int length, int height, int** map);
void drawMap(int** map, int length, int height, SDL_Window* window,SDL_Surface* screenSurface);
#endif //MAIN_C_SDL_H
