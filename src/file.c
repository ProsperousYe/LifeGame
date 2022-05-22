#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "map.h"
#include "file.h"
int lengthCount(char* filename){
    //count the file length
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
        return -1;
    }
    if(count_length==0){
        printf("FileIOError:the file is not exist or empty!\n");
        return -1;
    }
    return (count_length)/2;
}

int heightCount(char* filename){
    //count the file height
    FILE* file = fopen(filename,"r");
    char a;
    int count_height = 0;
    while((a=fgetc(file))!=EOF){
        if(a=='\n'){
            count_height++;
        }
    }
    fclose(file);
    if(count_height==0){
        printf("FileIOError:the file is not exist or empty!\n");
        return -1;
    }
    return count_height+1;
}

int** loadMapArray(char* filename,MapList* map_list){
    //load the map into a two division array
    if(map_list == NULL){
        printf("LoadMapError:The map list pointer is NULL\n");
    } else if(filename == NULL||strlen(filename)==0){
        printf("LoadMapError:The filename is empty\n");
    } else {
        FILE *file = fopen(filename, "r");
        int **map;
        map = (int **) malloc(map_list->height * sizeof(int));
        char **arr;
        arr = (char **) malloc(map_list->height * sizeof(char));
        for (int i = 0; i < map_list->height; i++) {
            arr[i] = (char *) malloc((map_list->length * 2) * sizeof(char));
            fgets(arr[i], 1000000000, file);
            char *subarr = strtok(arr[i], ",");
            map[i] = (int *) malloc(map_list->length * sizeof(int));
            int j = 0;
            while (subarr != NULL) {
                map[i][j] = atoi(subarr);
                subarr = strtok(NULL, ",");
                j++;
            }
        }
        fclose(file);
        return map;
    }
}

int** readMap(char* filename,int** map, int length, int height){
    //read the map is the height and length is known
    if(filename == NULL||strlen(filename)==0){
        printf("LoadMapError:The filename is empty\n");
    } else {
        FILE *file = fopen(filename, "r");//      char **arr;
        for (int i = 0; i < height; i++) {
            int a;
            for (int j = 0; j < length; j++) {
                fscanf(file,"%d", &a);
                map[i][j] = a;
                fgetc(file);
            }
            fgetc(file);
        }
        fclose(file);
        return map;
    }
}

