#include "JobTrie.h"
#include <stdlib.h>
#include <string.h>

static TrieNode* create_node() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    if (newNode) {
        newNode->isEndOfWord = 0;
        newNode->process = NULL;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

static void destroy_node(TrieNode* node) {
    if (!node) return;
    
    for (int i = 0; i < 26; i++) {
        destroy_node(node->children[i]);
    }
    free(node);
}

Trie* create_trie() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (trie) {
        trie->root = create_node();
    }
    return trie;
}

void insert_job(Trie* trie, const char* jobId, PCB* p) {
    if (!trie || !jobId || !p) return;
    
    TrieNode* current = trie->root;
    
    for (int i = 0; jobId[i] != '\0'; i++) {
        int index = jobId[i] - 'a';
        if (index < 0 || index >= 26) continue; // Skip non-lowercase letters
        
        if (!current->children[index]) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }
    
    current->isEndOfWord = 1;
    current->process = p;
}

PCB* search_job(Trie* trie, const char* jobId) {
    if (!trie || !jobId) return NULL;
    
    TrieNode* current = trie->root;
    
    for (int i = 0; jobId[i] != '\0'; i++) {
        int index = jobId[i] - 'a';
        if (index < 0 || index >= 26) return NULL;
        
        if (!current->children[index]) {
            return NULL;
        }
        current = current->children[index];
    }
    
    return (current && current->isEndOfWord) ? current->process : NULL;
}

void destroy_trie(Trie* trie) {
    if (trie) {
        destroy_node(trie->root);
        free(trie);
    }
}
