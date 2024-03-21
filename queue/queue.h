#ifndef QUEUE_H
#define QUEUE_H

typedef int t_elem;

typedef struct {
  int max; 
  int head;
  int tail;
  int n;
  t_elem *items;  
} t_queue;

int* out(t_queue *q, t_elem *elem);

int in(t_queue *q, t_elem elem);

int isEmpty(t_queue *q);

void destroyQueue(t_queue **q);

int isFull(t_queue *q);

t_queue* createQueue(int n);

void clearQueue(t_queue *q);

#endif 