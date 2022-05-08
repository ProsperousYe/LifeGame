#include<stdio.h>
#include "map.h"
int lengthCount(FILE* file){
    //int ret[2];
    char a;
    int count_length = 0;
    int count = 0;
    while((a=fgetc(file))!=EOF){
        count_length++;
        if(a=='\n'&&count_length== count){
            count = count_length;
            count_length = 0;
        } else if (a=='\n'&&count_length!=count){
            printf("LoadMapError:the length of each line is not the same in the file!");
        } else {
            continue;
        }
    }
    return count_length;
}

int heightCount(FILE* file){
    char a;
    int count_height = 0;
    while((a=fgetc(file))!=EOF){
        if(a=='\n'){
            count_height++;
        }
    }
    return count_height;
}

int loadMapArray(FILE* file,MapList* map_list){
    char a;
    int map[map_list->height][map_list->length];
    int position_x = 0;
    int position_y = 0;
    while((a=fgetc(file))!=EOF){
        if(a=='0'||a=='1'){
            map[position_y][position_x] = (int)a;
            position_x++;
        } else if(a=='\n'){
            position_y++;
        } else {
            printf("LoadMapError:the file has character that neither 0 nor 1");
            return 1;
        }
    }
    map_list->mapheader->map = map;
    return 0;
}

void storeMapArray(FILE* file, MapList* maplist){
    Map* this = maplist->mapheader;
    while(this->next!=NULL){
        this = this->next;
    }
    for(int i=0;i<maplist->height;i++){
        for(int j=0; j<maplist->length;j++){
            fputc(this->map[i][j], file);
        }
        fputc('\n',file);
    }
}
