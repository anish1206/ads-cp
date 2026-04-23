#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PCB.h"

#define MAX_QUEUE_SIZE 100

typedef struct {
    PCB* process;
    int priority;
} PQNode;

typedef struct {
    PQNode heap[MAX_QUEUE_SIZE];
    int size;
} PriorityQueue;

PriorityQueue* create_priority_queue();
void enqueue(PriorityQueue* pq, PCB* p, int priority);
PCB* dequeue(PriorityQueue* pq);
PCB* peek(PriorityQueue* pq);
int is_empty(PriorityQueue* pq);
void destroy_priority_queue(PriorityQueue* pq);

#endif
