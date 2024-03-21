#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    t_list *list;
    list = create_list(20);
    
    for(int i = 1; i <= 10; i++){
        append(list, 3);
    }
    t_list *copy = copy_unique_list_on2(list);

    print_list(copy);
    printf("N:%d\nMAX:%d", copy->n, copy->max);
    return 0;
}