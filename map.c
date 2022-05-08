void addMap(Map* map_list, int* map){
    Map* this = map_list->next;
    Map* new_map = (Map*)malloc(sizeof(Map));
    new_map->map = map;
    new_map->next = NULL;
    for(this!=NULL){
        this=this->next;
    }
    this=new_map;
}
