//
// Created by sony on 22-5-11.
//
#include <SDL2/SDL.h>
#include "sdl.h"
#include "file.h"
#include "map.h"

void drawGrids(MapList* maplist, char* filename,SDL_Window* window,SDL_Surface* screenSurface){
    int number;
    //loadMapArray(maplist,filename);
    Map* this = maplist->mapheader;
    if(maplist->height>maplist->length){
        number = maplist->height;
    } else {
        number = maplist->length;
    }
    while(this->next!=NULL){
        this = this->next;
    }
    int** map= this->map;
    puts("123");
    for(int i = 0;i<maplist->height;i++){
        for(int j = 0;j<maplist->length;j++){
            if(map[i][j] == 0){
                SDL_Rect rect = {j*300/number, i*300/number, 300/number, 300/number};
                SDL_FillRect(screenSurface,&rect, SDL_MapRGB(screenSurface->format,0XFFF,0XFFF,0));
            } else {
                SDL_Rect rect = {j*300/number, i*300/number, 300/number, 300/number};
                SDL_FillRect(screenSurface,&rect, SDL_MapRGB(screenSurface->format,0,0XFFF,0XFFF));
            }
        }
    }
    SDL_Delay(2000);
    SDL_UpdateWindowSurface(window);
}

void closeWindow(SDL_Window* window, SDL_Surface* surface){
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}