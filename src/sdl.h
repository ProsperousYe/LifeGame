//
// Created by sony on 22-5-11.
//

#ifndef MAIN_C_SDL_H
#define MAIN_C_SDL_H
#include "map.h"
//void showInit(void);
void drawGrids(MapList* maplist, char* filename,SDL_Window* window, SDL_Surface* screenSurface);
void closeWindow(SDL_Window* window, SDL_Surface* surface);
#endif //MAIN_C_SDL_H
