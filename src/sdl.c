//
// Created by sony on 22-5-11. SDL module
//
#include <SDL2/SDL.h>
#include "sdl.h"
#include "file.h"
#include "map.h"

void drawGrids(MapList* maplist, char* filename,SDL_Window* window,SDL_Surface* screenSurface){
    puts("enter drawGrids");
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
    int** map = this->map;
    //puts("123");
    puts("read last node");
    for(int i = 0;i<maplist->height;i++){
        for(int j = 0;j<maplist->length;j++){
            if(map[i][j] == 0){
                SDL_Rect rect = {j*300/number, i*300/number, 300/number, 300/number};
                SDL_FillRect(screenSurface,&rect, SDL_MapRGB(screenSurface->format,255,255,0));
            } else {
                SDL_Rect rect = {j*300/number, i*300/number, 300/number, 300/number};
                SDL_FillRect(screenSurface,&rect, SDL_MapRGB(screenSurface->format,0,255,255));
            }
        }
    }
    puts("exit draw");
}

void drawMap(int** map, int length, int height, SDL_Window* window,SDL_Surface* screenSurface){
    puts("enter drawMap");
    for(int i = 0;i<height;i++){
        for(int j = 0;j<length;j++){
            if(map[i][j] == 0){
                SDL_Rect rect = {j*50, i*50, 49, 49};
                SDL_FillRect(screenSurface,&rect, SDL_MapRGB(screenSurface->format,255,255,0));
            } else {
                SDL_Rect rect = {j*50, i*50, 49, 49};
                SDL_FillRect(screenSurface,&rect, SDL_MapRGB(screenSurface->format,0,255,255));
            }
        }
    }
    puts("exit draw");
}

void chooseGrids(SDL_Surface* surface, SDL_Window* window, int length, int height, int** map){
    int x;
    int y;
    while (1) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        SDL_Delay(1);
        switch(event.type){
            puts("1");
            case SDL_QUIT:
                SDL_DestroyWindow(window);
                SDL_Quit();
            case SDL_MOUSEBUTTONUP:
                x = event.button.x/50;
                y = event.button.y/50;
                printf("position:(%d, %d)\n",x, y);
                if(map[y][x] == 0){
                    map[y][x] = 1;
                } else {
                    map[y][x] = 0;
                }
                drawMap(map, length, height, window, surface);
                SDL_UpdateWindowSurface(window);
                break;
            case SDL_KEYDOWN:
                return;
            default:
                break;
        }
    }
}