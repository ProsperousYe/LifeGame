#include <stdio.h>
#include <string.h>
#include "file.h"
#include "run.h"
#include "map.h"
#include "initialize.h"
int main(int argc, char* argv[]) {
    FILE* file = fopen(argv[1],"r");
    MapList* map_list = NULL;
    initialize(file, map_list);
    int i;
    int num = (int)argv[0];
    for(i=0;i<num;i++){
        int** map = computeMap(map_list);
        addMap(map_list, map);
    }
    FILE* storefile = fopen(argv[2],"w");
    storeMapArray(storefile, map_list);
    return 0;
}



