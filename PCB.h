#ifndef PCB_H
#define PCB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char job_id[50];
    int burst_time;
    int memory_req;
    int is_active;  // 1 = active, 0 = scheduled/removed
} PCB;

PCB* create_pcb(const char* id, int burst, int mem);
void print_pcb_details(PCB* p);
void destroy_pcb(PCB* p);

#endif