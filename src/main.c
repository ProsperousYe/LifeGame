#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "file.h"
#include "run.h"
#include "map.h"
#include "initialize.h"
#include "sdl.h"
#include <unistd.h>

void start(int argc, char* argv[]){
    //system("./GameofLife 4 game.txt history.txt");
    SDL_Window  *window = NULL;
    SDL_Surface *surface = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr,"SDL_Init; %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 300,
                                  SDL_WINDOW_SHOWN);
        if (window!=NULL) {
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255,255));
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
    int num = strtol(argv[1],argv,10);

    for(i=0;i<num;i++) {
        puts("running...");
        printf("\nthe %d\n",i);
        addMap(map_list, loadMapArray(storefile, map_list));
        computeMap(map_list, storefile);
        drawGrids(map_list,storefile, window, surface);
        SDL_Delay(1000);
        puts("...");
        SDL_UpdateWindowSurface(window);
    }


    //puts("1234");
    puts("finish draw");
    Map* p = map_list->mapheader;
    Map* q = NULL;

    while(p->next!=NULL){
        //free(p->map);
        //p->map = NULL;
        q = p->next;
        //free(p->map);
        free(p);
        p = q;
    }
    free(map_list);
    map_list = NULL;
    sleep(1);
    //closeWindow(window, surface);
    puts("free...");
    //system("clear");
    //puts("enter closeWindow");
    //SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_FreeSurface(surface);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    if(argc == 4){
        start(argc, argv);
    } else if(argc == 5 && strcmp("-i",argv[4]) == 0){
        char storefile[50] = "./data/";
        strcat(storefile, argv[3]);
        int length;
        int height;
        printf("please input the length you want:");
        scanf("%d", &length);
        printf("please input the height you want:");
        scanf("%d",&height);
        MapList* map_list = (MapList*)malloc(sizeof(MapList));
        Map* mapheader = (Map*)malloc(sizeof(Map));
        mapheader->next = NULL;
        mapheader->map = NULL;
        map_list->mapheader = mapheader;
        map_list->length = length;
        map_list->height = height;
        SDL_Window  *window = NULL;
        SDL_Surface *surface = NULL;
        int** initmap = (int**)malloc(sizeof(int)*height*2);
        for(int i = 0;i<height;i++){
            initmap[i] = (int*)malloc(sizeof(int)*length*2);
            for(int j =0; j<length;j++){
                initmap[i][j] = 0;
            }
        }
        FILE* history3 = fopen(storefile, "w");
        for(int i = 0;i<height;i++){
            for(int j =0; j<length;j++){
                fprintf(history3,"%d,", initmap[i][j]);
            }
            fprintf(history3,"\n");
        }
        fclose(history3);
        Map* new = (Map*)malloc(sizeof(Map));
        mapheader->next = new;
        new->map = initmap;
        new->next  = NULL;
        //create the SDL window and surface
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            fprintf(stderr,"SDL_Init; %s\n", SDL_GetError());
        } else {
            window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, length*50, height*50,
                                      SDL_WINDOW_SHOWN);
            if (window!=NULL) {
                surface = SDL_GetWindowSurface(window);
                SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
                SDL_UpdateWindowSurface(window);
            }
        }
        drawMap(initmap, length, height, window, surface);
        chooseGrids(surface, window, length, height, initmap);
        FILE *historyfile = fopen(storefile, "w");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                fprintf(historyfile, "%d,", initmap[i][j]);
            }
            fprintf(historyfile, "\n");
        }
        fclose(historyfile);
        while(1) {
            int x;
            int y;
            SDL_Event event;
            SDL_WaitEvent(&event);
            switch (event.type) {
                case SDL_QUIT:
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                case SDL_MOUSEBUTTONUP:
                    x = event.button.x/50;
                    y = event.button.y/50;
                    printf("position:(%d, %d)\n",x, y);
                    if(initmap[y][x] == 0){
                        initmap[y][x] = 1;
                    } else {
                        initmap[y][x] = 0;
                    }
                    drawMap(initmap, length, height, window, surface);
                    SDL_UpdateWindowSurface(window);
                    break;
                case SDL_KEYDOWN:
                    computeGrids(initmap, storefile,length, height);
                    initmap = readMap(storefile, initmap, length, height);
                    drawMap(initmap, length, height, window, surface);
                    SDL_UpdateWindowSurface(window);
                default:
                    break;
            }

//            if(event.type != SDL_QUIT){
//                computeGrids(initmap, storefile,length, height);
//                initmap = readMap(storefile, initmap, length, height);
//                drawMap(initmap, length, height, window, surface);
//                SDL_UpdateWindowSurface(window);
//                sleep(2);
//            } else {
//                break;
//            }
        }
        END:
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    return 0;
}



