#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "map.h"
#include "file.h"
int lengthCount(char* filename){
    puts("123");
    FILE* file = fopen(filename,"r");
    int count_length = 0;
    while(fgetc(file)!='\n'){
        count_length++;
    }
    fclose(file);
    printf("%d", count_length);
    if((count_length%2)!=0){
        printf("FileIOError:the file format is not right!\n");
        abort();
    }
    if(count_length==0){
        printf("FileIOError:it is an empty file!\n");
        abort();
    }
    return (count_length)/2;
}

int heightCount(char* filename){
    FILE* file = fopen(filename,"r");
    char a;
    int count_height = 0;
    while((a=fgetc(file))!=EOF){
        if(a=='\n'){
            count_height++;
        }
    }
    fclose(file);
    return count_height+1;
}

int** loadMapArray(char* filename,MapList* map_list){
    FILE* file = fopen(filename,"r");
    //puts("123");
    int **map;
    //printf("length = %d", map_list->length);
    //printf("height = %d", map_list->height);
    map = (int**)malloc(map_list->height*sizeof(int));
    //map[0] = (int*)malloc(sizeof(int)*map_list->length);
//    int position_x = 0;
//    int position_y = 0;
    //printf("%c",a);
//    char a;
//    while((a=fgetc(file))!=EOF){
//        //printf("%c",a);
//        //printf("x = %d ",position_x);
//        //printf("y = %d\n",position_y);
//        //printf("%d, %d = %d\n", position_x, position_y, map[position_y][position_x]);
//        for(int i =0;i<position_y-1;i++){
//            for(int j=0;j<map_list->length;j++){
//                printf("%d ",map[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//        if(a=='0'||a=='1'){
//            map[position_y][position_x] = a - '0';
//            //printf("%d, %d = %d\n", position_x, position_y, map[position_y][position_x]);
//            position_x++;
//        } else if(a=='\n'){
//            //printf("\n");
//            position_x=0;
//            position_y++;
//            map[position_y] = (int*)malloc(sizeof(int)*map_list->length);
//        } else {
//            printf("LoadMapError:the file has character that neither 0 nor 1");
//        }
//
//    }
    //printf("123");
    char **arr;
    arr = (char**)malloc(map_list->height*sizeof(char));
    for(int i = 0;i<map_list->height;i++){
        //puts("2");
        //printf("%d: ",i);
        arr[i] = (char*)malloc((map_list->length*2)*sizeof(char));
        fgets(arr[i],1000000000,file);
        char *subarr = strtok(arr[i],",");
        map[i] = (int*)malloc(map_list->length*sizeof(int));
        int j =0;
        //printf("subarr = %s, arr[%d] = %s\n", subarr, i, arr[i]);
        while(subarr!=NULL){
            //puts("1 ");
            //printf("%s", subarr);
            map[i][j] = atoi(subarr);
            //printf("%d ", map[i][j]);
            subarr = strtok(NULL, ",");
            //printf("%s ", subarr);
            j++;
        }
        //printf("\n");
    }
    //printf("123");
//    for(int i =0;i<map_list->height;i++){
//        for(int j=0;j<map_list->length;j++){
//            printf("%d ",map[i][j]);
//        }
//        printf("\n");
//    }
    //printf("123");
    fclose(file);
    return map;
}

