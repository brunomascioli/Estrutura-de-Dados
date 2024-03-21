#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

t_queue* createQueue(int n){
  t_queue *q = (t_queue *)malloc(sizeof(t_queue));
  q->items = malloc(sizeof(t_elem) * n);
  q->max = n;
  q->head = 0;
  q->tail = 0;
  q->n = 0;
  return q;
}

int in(t_queue *q, t_elem elem){
  if(q->n == q->max){
    return -1;
  } 
  q->items[q->tail] = elem;
  q->tail = (q->tail + 1) % q->max;
  q->n++;
  return 0;
}

int* out(t_queue *q, t_elem *elem){
  if (q->n == 0){
    return NULL;
  }
  
  *elem = q->items[q->head];
  q->head = (q->head + 1) % q->max;
  q->n--;
  return elem;
}

int getSize(t_queue *q){
  if(q == NULL){
    return 0;
  }
  return q->n;
}

int isEmpty(t_queue *q){
  return q->n == 0 ? 0 : -1;
}

int isFull(t_queue *q){
  return q->n == q->max ? 0 : -1;
}

void destroyQueue(t_queue **q){
  if(q == NULL) return;
  free((*q)->items);
  free(*q);
  *q = NULL;
}

void clearQueue(t_queue *q){
  q->head = 0;
  q->tail = 0;
  q->n = 0;
}