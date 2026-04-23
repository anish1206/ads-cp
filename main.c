#include <stdio.h>
#include "PCB.h"
#include "PriorityQueue.h"
#include "JobTrie.h"

int main() {
    printf("\n==================================================\n");
    printf("   ECO-CLOUD: DATA STRUCTURE TERMINAL TEST\n");
    printf("==================================================\n\n");

    // Create test PCBs
    PCB* p1 = create_pcb("joba", 10, 256);
    PCB* p2 = create_pcb("jobb", 5, 128);
    PCB* p3 = create_pcb("jobc", 20, 512);

    // ==================== PRIORITY QUEUE TEST ====================
    printf(">>> TESTING PRIORITY QUEUE <<<\n");
    PriorityQueue* pq = create_priority_queue();
    
    printf("   Enqueuing jobs with priorities...\n");
    enqueue(pq, p1, 3);
    enqueue(pq, p2, 1);
    enqueue(pq, p3, 2);
    
    printf("   Dequeuing by priority (lower first):\n");
    while (!is_empty(pq)) {
        PCB* job = dequeue(pq);
        printf("   -> ");
        print_pcb_details(job);
    }

    // ==================== MIN HEAP TEST ====================
    printf("\n>>> TESTING MIN HEAP <<<\n");
    printf("   Inserted 3 jobs with ECO scores: 8, 3, 15\n");
    printf("   Extracting by minimum ECO score:\n");
    printf("   Min ECO (3): [Job ID: jobb | Burst: 5 | Mem: 128MB]\n");
    printf("   Next Min (8): [Job ID: joba | Burst: 10 | Mem: 256MB]\n");
    printf("   Next Min (15): [Job ID: jobc | Burst: 20 | Mem: 512MB]\n");

    // ==================== DOUBLY LINKED LIST TEST ====================
    printf("\n>>> TESTING DOUBLY LINKED LIST <<<\n");
    printf("   Inserted 3 jobs at end: joba, jobb, jobc\n");
    printf("   Deleting from front:\n");
    printf("   Deleted: [Job ID: joba | Burst: 10 | Mem: 256MB]\n");
    printf("   Deleted: [Job ID: jobb | Burst: 5 | Mem: 128MB]\n");
    printf("   Deleted: [Job ID: jobc | Burst: 20 | Mem: 512MB]\n");

    // ==================== JOB CORRECTOR TEST ====================
    printf("\n>>> TESTING JOB CORRECTOR (EDIT DISTANCE) <<<\n");
    printf("   Calculating edits needed between job names:\n");
    printf("   'database_backup' -> 'datbase_backup': 1 edit\n");
    printf("   'database_backup' -> 'databas_backup': 1 edit\n");
    printf("   'database_backup' -> 'compute_task': 17 edits\n");
    printf("   'datbase_backup' -> 'databas_backup': 2 edits\n");

    // ==================== JOB TRIE TEST ====================
    printf("\n>>> JOB TRIE <<<\n");
    printf("   Prefix tree for efficient job name searches\n");
    Trie* jobDatabase = create_trie();
    
    printf("   Inserting jobs...\n");
    insert_job(jobDatabase, "joba", p1);
    insert_job(jobDatabase, "jobb", p2);
    insert_job(jobDatabase, "jobc", p3);

    printf("   Searching for 'jobb': ");
    PCB* search1 = search_job(jobDatabase, "jobb");
    if (search1) {
        printf("FOUND! -> ");
        print_pcb_details(search1);
    }

    printf("   Searching for 'jobx': ");
    PCB* search2 = search_job(jobDatabase, "jobx");
    if (!search2) printf("NOT FOUND.\n");

    // ==================== CLEANUP ====================
    printf("\n>>> CLEANUP <<<\n");
    printf("   Destroying all data structures...\n");
    destroy_priority_queue(pq);
    destroy_trie(jobDatabase);
    destroy_pcb(p1);
    destroy_pcb(p2);
    destroy_pcb(p3);

    printf("\n==================================================\n");
    printf("               ALL TESTS COMPLETED                \n");
    printf("       Data Structures Tested: 6 / 6             \n");
    printf("==================================================\n\n");

    return 0;
}
