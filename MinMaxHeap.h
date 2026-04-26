#ifndef MINMAX_HEAP_H
#define MINMAX_HEAP_H

#include "PCB.h"

#define MAX_HEAP_SIZE 100

// MinMax Heap Node: stores process and its efficiency score
typedef struct {
    PCB* process;
    int efficiency_score;  // Lower = more efficient
} HeapNode;

typedef struct {
    HeapNode heap[MAX_HEAP_SIZE];
    int size;
} MinMaxHeap;

// Core Operations
MinMaxHeap* create_minmax_heap();
void minmax_insert(MinMaxHeap* mmh, PCB* p, int score);
PCB* minmax_extract_min(MinMaxHeap* mmh);
PCB* minmax_extract_max(MinMaxHeap* mmh);
void minmax_delete_by_pcb(MinMaxHeap* mmh, PCB* p);
PCB* minmax_peek_min(MinMaxHeap* mmh);
PCB* minmax_peek_max(MinMaxHeap* mmh);
int minmax_is_empty(MinMaxHeap* mmh);
void minmax_destroy(MinMaxHeap* mmh);

// Helper - Get level (0-indexed)
int get_level(int index);

#endif
