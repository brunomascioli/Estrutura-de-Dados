#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list* create_list(){
	t_list* list = (t_list*) malloc(sizeof(t_list));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

int is_empty(t_list* list){
	return list->size == 0 ? 1 : 0; 
}

int append(t_list* list, int elem) {
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->item = elem;
    node->next = NULL;
    if (is_empty(list)) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
    return 1;
}

int print_list(t_list* list){
	if (list->size == 0){
		printf("[]\n");
		return 0;
	}
	
	t_node* node = list->head;
	while (node->next != NULL){
		printf("%d ", node->item);
		node = node->next;
	}
	printf("%d", node->item);
	printf("\n");
	return 1;
}

t_node* get_node_item(t_list* list, int item){
	t_node* node = list->head;
	while (node->next != NULL){
		if(node->item == item) return node;
		node = node->next;
	}
	return NULL;	
}

t_node* get_item_by_index(t_list* list, int index){
	if(index < 0 || index >= list->size || list->size == 0){
		return NULL;
	}
	t_node* node = list->head;
	for(int i = 0; i < index; i++) node = node->next;
	return node;
}
// Retorna o nó no início da lista
t_node* peek_back(t_list* list){
	if(list->size == 0) return NULL;
	t_node* node = list->head;
	while (node->next != NULL){
		node = node->next;
	}
	return node;
}

// Retorna o nó no final da lista
t_node* peek_front(t_list* list){
	return NULL;
}

int clear(t_list *list){
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return 1;
}

void destroy_node(t_node* node){
	if(node == NULL){
		free(node);
		return;
	}
	t_node* aux = node->next;
	free(node);
	destroy_node(aux);
	return;
}

int destroy_list(t_list* list){
	destroy_node(list->head);
	int len_list = size(list);
	return len_list;
}

int size(t_list* list){
	return list->size;
}