#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list *create_list(int size){
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->max = size;
    // (*list).max == list->max
    list->n = 0;
    list->items = (int *)malloc(sizeof(int) * size);
    return list;
}

int size(t_list *list){
    return list->n;
}

int print_list(t_list *list){
    for (int i = 0; i < list->n; i++){
        printf("%d\n", list->items[i]);
    }
    return 1;
}

int is_full(t_list *list){
    return list->max == list->n;
}

int is_empty(t_list *list){
    return list->n == 0;
}

int destroy_list(t_list *list){
    free(list->items);
    free(list);
    return 1;
}

int append(t_list *list, int elem){
    if (!is_full(list)){
        list->items[list->n] = elem;
        list->n++;
        return 1;
    }
    return 0;
}

int index_of(t_list *list, int elem){
    for (int i = 0; i < size(list); i++){
        if (list->items[i] == elem){
            return i;
        }
    }
    return -1;
}

int is_valid_index(t_list *list, int index){
    if(index < 0 || index > list->n) return 0;
    return 1;
}

int get(t_list *list, int index, int *elem){
    if(is_valid_index(list, index)){
        *elem = list->items[index];
        return 1;
    }
    return 0;
}

int count(t_list *list, int elem){
    int c = 0;
    for(int i = 0; i < size(list); i++){
        if(list->items[i] == elem) c++;
    }
    return c;
}

int remove_elem(t_list *list, int index){
    for(int i = index; i < size(list) - 1; i++){
        list->items[i] = list->items[i+1];
    }
    list->n--;
    return 1;
}

int remove_by_element(t_list *list, int elem){
    for(int i = 0; i < size(list); i ++){
        if(list->items[i] == elem){
            remove_elem(list, i);
            return 1;
        }
    }
    return 0;
}
int remove_by_index(t_list *list, int index){
    remove_elem(list, index);
    return 1;
}

int insert(t_list *list, int elem, int index){
    if(!is_valid_index(list, index) || is_full(list)) return 0;
    if(index == list->n){
        list->items[index] = elem;
    }
    for(int i = list->n; i >= index; i--){
        list->items[i + 1] = list->items[i];
    }
    list->n++;
    list->items[index] = elem;
    return 1;
}

int clear(t_list *list){
    list->n = 0;
    return 1;
}

int update(t_list *list, int elem, int index){
    if(!is_valid_index(list, index)) return 0;
    list->items[index] = elem;
    return 1;
}

t_list* copy_list(t_list *list){
    t_list *copy = (t_list *)malloc(sizeof(t_list));
    copy->n = list->n;
    copy->max = list->max;
    copy->items = (int *)malloc(sizeof(int) * copy->max);
    for(int i = 0; i < copy->n; i++){
        copy->items[i] = list->items[i];
    }
    return copy;
}

int contains_value(int *list, int size, int value){
    for(int i = 0; i < size; i++){
        if(list[i] == value) return 1;
    }
    return 0;
}

t_list* copy_unique_list_on2(t_list *list){
    t_list *copy = (t_list *)malloc(sizeof(t_list));
    copy->max = list->max;
    copy->items = (int *)malloc(sizeof(int) * copy->max);
    int pos = 0;
    for(int i = 0; i < size(list); i++){
        if(!contains_value(copy->items, pos, list->items[i])){
            copy->items[pos++] = list->items[i];
        }
    }
    copy->n = pos;
    return copy;
}