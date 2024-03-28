#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    t_list* list = create_list();
    append(list, 3);
    append(list, 4);
    append(list, 7);
    append(list, 100);
    print_list(list);
    clear(list);
    append(list, 11);
    append(list, 40);
    append(list, 50);
    print_list(list);
    printf("list size: %d\n", list->size);
    t_node* node = get_item_by_index(list, 1);
    printf("%d\n", node->item);
    t_node* node_back = peek_back(list);
    printf("%d\n", node_back->item);
    printf("FIM do programa\n");
    return 0;
}