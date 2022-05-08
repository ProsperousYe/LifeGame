#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "run.h"
#include "map.h"
int main(int argc, char* argv[]) {
    FILE* file = fopen(argv[0],'r');
    height=heightCount(file);
    length= lengthCount(file);
    int* map[height][length] = (int*)malloc(height*length*sizeof(int));
    Map* map_header = (Map*)malloc(sizeof(Map));
    Map* map_list;
    map_list->map =NULL;
    map_list->next = map_header;
    map_header->map=MULL;
    map_header->next=MULL;
    loadMapArray(file, map);
    computeMap(map, height, length);

    return 0;
}



