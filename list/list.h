#ifndef LIST_H
#define LIST_H

typedef struct {
    int max;
    int n;
    int *items;
} t_list;

t_list* create_list(int size);

int destroy_list(t_list *list);

int size(t_list *list);

int is_full(t_list *list);

int is_empty(t_list *list);

int append(t_list *list, int elem);

int insert(t_list *list, int index, int elem);

int print_list(t_list *list);

int index_of(t_list *list, int elem);

int get(t_list *list, int index, int *elem);

int count(t_list *list, int elem);

int remove_elem(t_list *list, int index);

int remove_by_element(t_list *list, int elem);

int remove_by_index(t_list *list, int index);

int clear(t_list *list);

int update(t_list *list, int elem, int index);

int is_valid_index(t_list *list, int index);

t_list* copy_list(t_list *list);

t_list* copy_unique_list_on2(t_list *list);

int contains_value(int *list, int size, int value);

#endif /* LIST_H */