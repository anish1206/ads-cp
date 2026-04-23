#include "PCB.h"

PCB* create_pcb(const char* id, int burst, int mem) {
    PCB* p = (PCB*)malloc(sizeof(PCB));
    if (p) {
        strcpy(p->job_id, id);
        p->burst_time = burst;
        p->memory_req = mem;
    }
    return p;
}

void print_pcb_details(PCB* p) {
    if (p) {
        printf("[Job ID: %s | Burst: %d | Mem: %dMB]\n", p->job_id, p->burst_time, p->memory_req);
    }
}

void destroy_pcb(PCB* p) {
    if (p) {
        free(p);
    }
}
