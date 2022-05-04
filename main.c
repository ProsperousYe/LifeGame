#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Cell_{
    int state;
    int position[2];
    struct Cell* up;
    struct Cell* down;
    struct Cell* left;
    struct Cell* right;
}Cell;

typedef struct Map_{
    int length;
    int height;
    struct Cell* init_cell;
    struct Map* next;
}Map;

Map* initialize(){
    Map* map = (Map*)malloc(sizeof(Map));
    Cell* initial_cell = (Cell*)malloc(sizeof(Cell));
    map->init_cell = initial_cell;
    initial_cell->state = NULL;
    initial_cell->position[0] = 0;
    initial_cell->position[1] = 0;
    initial_cell->down = NULL;
    initial_cell->up = NULL;
    initial_cell->left = NULL;
    initial_cell->right = NULL;
    return map;
}

Cell* AddCell(Cell* add_position, Cell* new_cell, int direction){
    switch(direction){
        case 1:
            add_position->right = new_cell;
            new_cell->left = add_position;
            new_cell->up = NULL;
            new_cell->down = NULL;
            break;
        case 2:
            add_position->left = new_cell;
            new_cell->right = add_position;
            new_cell->up = NULL;
            new_cell->down = NULL;
            break;
        case 3:
            add_position->down = new_cell;
            new_cell->up = add_position;
            new_cell->left = NULL;
            new_cell->right = NULL;
            break;
        case 4:
            add_position->up = new_cell;
            new_cell->down = add_position;
            new_cell->left = NULL;
            new_cell->right = NULL;
            break;
        default:
            printf("AddCellError: direction number invalid!");
            break;
    }
}

Map* LoadMap(FILE* file, Map* map){
    Cell* cell_point = map->init_cell;
    Cell* line_point = map->init_cell;
    int direction = 1;
    int position_x = 1;
    int position_y = 1;
    char state;
    while((state = fgetc(file))!=EOF){
        if(state=='1'||state=='0'){
            Cell* cell = (Cell*)malloc(sizeof(Cell));
            AddCell(cell_point,cell, direction);
            cell->state = (int)state;
            cell->position[0] = position_x;
            cell->position[1] = position_y;
            if(position_y != 1){
                Cell* up_cell = line_point->up;
                while(up_cell->position[0]!=cell->position[0]){
                    up_cell = up_cell->right;
                }
                AddCell(up_cell,cell,3);
            }
            position_x++;
            if(position_x){
                line_point = cell;
                direction = 1;
            }
            cell_point = cell_point->right;
            continue;
        } else if(state=='\n'){
            position_y++;
            position_x = 1;
            cell_point = line_point;
            direction = 3;
            continue;
        } else{
            printf("LoadMapError:the file has character that neither 0 nor 1");
            return 0;
        }
    }
    return map;
}

int main(int argc, char* argv[]){
    Map* map = initialize();
    FILE *file = fopen(argv[0],"r");
    LoadMap(file, map);
    return 0;
}



