int* copyArray(int* old_map){
    int new_map[length(map)][length(map[0])] = malloc(length(map)*length(map[0])*sizeof(int));
    int i;
    for(i = 0; i<length(map); i++){
        int j;
        for(j = 0;j<length(map[i]);j++){
            new_map[i][j] = old_map[i][j];
        }
    }
    return new_map;
}

int* computeMap(int* map, int height, int length){
int* map_after = copyArray(map);
int i;
int env;
for(i=0;i<height;i++){
    int j;
    for(j=0;j<length;j++){
            env = map_before[i-1][j-1]+map_before[i-1][j]+map_before[i-1][j+1]
                  +map_before[i][j-1]+map_before[i][j+1]
                  +map_before[i+1][j-1]+map_before[i+1][j]+map_before[i+1][j+1];
            if(map_before[i][j]==1){
                if(env == 2 || env == 3){
                map_after[i][j]=1;
                } else {
                map_after[i][j]=0;
                }
            } else {
                if(env == 3){
                map_after[i][j] = 1;
                } else {
                map_after[i][j] = 0;
                }
                }
            }
        }
}