//
// Created by sony on 22-5-7.
//
#include<stdio.h>

int fileReadingTest(FILE file){

}

int main(int argc, char* argv[]){
    FILE* file = fopen(argv[0],"r");
    char a;
    int count_height = 0;
    while((a=fgetc(file))!=EOF){
        if(a=='\n'){
            count_height++;
        }
    }

    return count_height;
}