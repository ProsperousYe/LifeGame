#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "file.h"
#include "run.h"
#include "map.h"
#include "initialize.h"
#include "sdl.h"

int main(int argc, char* argv[]) {
    SDL_Window  *window = NULL;
    SDL_Surface *surface = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr,"SDL_Init; %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 300,
                                  SDL_WINDOW_SHOWN);
        if (window!=NULL) {
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
        }
    }
    char initfile[50] = "./data/";
    char storefile[50] = "./data/";
    strcat(initfile, argv[2]);
    strcat(storefile, argv[3]);
    char com1[50] = "touch ";
    strcat(com1, initfile);
    char com2[50] = "touch ";
    strcat(com2, storefile);
    system(com1);
    system(com2);
    printf("%s\n", initfile);
    printf("%s\n", storefile);
    MapList* map_list = (MapList*)malloc(sizeof(MapList));
    initialize(initfile, map_list);
    Map* this = map_list->mapheader;
    while(this->next!=NULL){
        this = this->next;
    }
    FILE* file = fopen(storefile,"w");
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
        computeMap(map_list, storefile);
        drawGrids(map_list,storefile, window, surface);
    }
    closeWindow(window, surface);
    Map* p = map_list->mapheader;
    Map* q;
    while(p->next!=NULL){
        q = p->next;
        free(p);
        p = q;
    }
    free(q);
    free(map_list);
    return 0;
}



