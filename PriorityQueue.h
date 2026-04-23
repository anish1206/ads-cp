#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PCB.h"

typedef struct Node {
    PCB* process;
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

PriorityQueue* create_priority_queue();
void enqueue(PriorityQueue* pq, PCB* p, int priority);
PCB* dequeue(PriorityQueue* pq);
PCB* peek(PriorityQueue* pq);
int is_empty(PriorityQueue* pq);
void destroy_priority_queue(PriorityQueue* pq);

#endif
