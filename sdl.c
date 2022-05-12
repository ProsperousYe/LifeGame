//
// Created by sony on 22-5-11.
//
#include <SDL2/SDL.h>
#include "sdl.h"
#include "file.h"
#include "map.h"
//SDL_Surface* showInit(void){
//    puts("sdl");
//    SDL_Window  *window = NULL;
//    SDL_Surface *screenSurface = NULL;
//    if(SDL_Init(SDL_INIT_VIDEO) < 0){
//        fprintf(stderr,"SDL_Init; %s\n", SDL_GetError());
//    } else {
//        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,300,SDL_WINDOW_SHOWN);
//        if(window){
//            screenSurface = SDL_GetWindowSurface(window);
//            SDL_FillRect(screenSurface,NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
//            SDL_UpdateWindowSurface(window);
//            SDL_Delay(2000);
//        }
//    }
//    //puts("sdl");
//    //SDL_DestroyWindow(window);
//    //SDL_Quit();
//    return screenSurface;
//}

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
        //printf("\n");
    }
    SDL_Delay(2000);
    SDL_UpdateWindowSurface(window);
}

void closeWindow(SDL_Window* window, SDL_Surface* surface){
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}