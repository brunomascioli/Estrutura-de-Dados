#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef int *t_elem;

typedef struct {
    int max;
    int index_top;
    t_elem *items;
} t_stack;

t_stack* create_stack(int n){
    t_stack *p = (t_stack *) malloc(sizeof(t_stack));
    p->max = n;
    p->items = (t_elem *) malloc(sizeof(t_elem) * n);
    p->index_top = -1;
    return p;
}

void destroy_stack(t_stack *p){
    free(p->items);
    free(p);
}

int is_full(t_stack *p){
    if(p->index_top == p->max) return 1;
    return 0;
}