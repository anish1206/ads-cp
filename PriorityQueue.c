#include "PriorityQueue.h"
#include <stdlib.h>

PriorityQueue* create_priority_queue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq) {
        pq->front = NULL;
    }
    return pq;
}

void enqueue(PriorityQueue* pq, PCB* p, int priority) {
    if (!pq || !p) return;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    
    newNode->process = p;
    newNode->priority = priority;
    newNode->next = NULL;
    
    if (!pq->front || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node* curr = pq->front;
        while (curr->next && curr->next->priority <= priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

PCB* dequeue(PriorityQueue* pq) {
    if (!pq || !pq->front) return NULL;
    
    PCB* result = pq->front->process;
    Node* temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
    return result;
}

PCB* peek(PriorityQueue* pq) {
    if (!pq || !pq->front) return NULL;
    return pq->front->process;
}

int is_empty(PriorityQueue* pq) {
    return !pq || pq->front == NULL;
}

void destroy_priority_queue(PriorityQueue* pq) {
    if (!pq) return;
    
    while (!is_empty(pq)) {
        dequeue(pq);
    }
    free(pq);
}
