#include "PCB.h"

PCB* create_pcb(const char* id, int burst, int mem) {
    PCB* p = (PCB*)malloc(sizeof(PCB));
    if (p) {
        strncpy(p->job_id, id, sizeof(p->job_id) - 1);
        p->job_id[sizeof(p->job_id) - 1] = '\0';
        p->burst_time = burst;
        p->memory_req = mem;
        p->is_active = 1;  // New jobs are active
    }
    return p;
}

void print_pcb_details(PCB* p) {
    if (p) {
        printf("    Job ID: %s\n", p->job_id);
        printf("    Burst Time: %d units\n", p->burst_time);
        printf("    Memory Required: %d MB\n", p->memory_req);
        printf("\n");
    }
}

void destroy_pcb(PCB* p) {
    if (p) {
        free(p);
    }
}
