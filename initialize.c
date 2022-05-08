#include<stdlib.h>
int* initialize(int length, int height){
    int*map=(int*)malloc(length*height*sizeof(int));
    return map;
}