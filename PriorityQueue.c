#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

PriorityQueue* create_priority_queue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq) {
        pq->size = 0;
    }
    return pq;
}

void swap_nodes(PQNode* a, PQNode* b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

void enqueue(PriorityQueue* pq, PCB* p, int priority) {
    if (!pq || !p) return;
    if (pq->size >= MAX_QUEUE_SIZE) {
        printf("Priority Queue is full\n");
        return;
    }
    
    pq->heap[pq->size].process = p;
    pq->heap[pq->size].priority = priority;
    
    int i = pq->size;
    pq->size++;

    while (i > 0 && pq->heap[(i - 1) / 2].priority > pq->heap[i].priority) {
        swap_nodes(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

PCB* dequeue(PriorityQueue* pq) {
    if (!pq || pq->size == 0) {
        return NULL;
    }

    PCB* result = pq->heap[0].process;

    // Replace root with last element
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    int i = 0;

    // Trickle down
    while (2 * i + 1 < pq->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int smallest = left;
        if (right < pq->size && pq->heap[right].priority < pq->heap[left].priority) {
            smallest = right;
        }

        if (pq->heap[i].priority > pq->heap[smallest].priority) {
            swap_nodes(&pq->heap[i], &pq->heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    return result;
}

PCB* peek(PriorityQueue* pq) {
    if (!pq || pq->size == 0) return NULL;
    return pq->heap[0].process;
}

int is_empty(PriorityQueue* pq) {
    return !pq || pq->size == 0;
}

void destroy_priority_queue(PriorityQueue* pq) {
    if (pq) {
        free(pq);
    }
}
