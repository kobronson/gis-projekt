#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"



struct t_MinHNode* mh_newMinHNode(uint16_t v, uint16_t key){
    struct t_MinHNode* tmp;
	tmp = malloc(sizeof(struct t_MinHNode));
    tmp->element = v;
    tmp->key = key;
    return tmp;
}
 

struct t_MinH* mh_createMinH(uint16_t mh_len){
    struct t_MinH* min_heap;
    min_heap = malloc(sizeof(struct t_MinH));
    min_heap->mh_pos = malloc(mh_len * sizeof(uint16_t));
    min_heap->mh_size = 0;
    min_heap->mh_len = mh_len;
    min_heap->mh_nodes = malloc(mh_len * sizeof(struct t_MinHNode*));
    return min_heap;
}

void mh_swap(struct t_MinHNode** a, struct t_MinHNode** b){
    struct t_MinHNode* tmp;
	tmp = *a;
    *a = *b;
    *b = tmp;
}

void mh_heapify(struct t_MinH* min_heap, uint16_t idx){
    
	struct t_MinHNode *minNode;
	struct t_MinHNode *idxNode;
	uint16_t min, l,r;
	
	
    min = idx;
    l = 2 * idx + 1;
    r = 2 * idx + 2;
 
	//Znajdź najmniejszy 
    if (l < min_heap->mh_size && min_heap->mh_nodes[l]->key < min_heap->mh_nodes[min]->key ) min = l; 
    if (r < min_heap->mh_size && min_heap->mh_nodes[r]->key < min_heap->mh_nodes[min]->key ) min = r;
 
	//Napraw - zamien indeksy
    if (min != idx){
       
        minNode = min_heap->mh_nodes[min];
        idxNode = min_heap->mh_nodes[idx];
 
        
        min_heap->mh_pos[minNode->element] = idx;
        min_heap->mh_pos[idxNode->element] = min;
 
       
        mh_swap(&min_heap->mh_nodes[min], &min_heap->mh_nodes[idx]);
 
        mh_heapify(min_heap, min);
    }
}




struct t_MinHNode* mh_cutMinHNode(struct t_MinH* min_heap){
    
	struct t_MinHNode *last_node;
	struct t_MinHNode *root;
	
	if (min_heap->mh_size == 0) return NULL;
 
   
    root = min_heap->mh_nodes[0];   
    last_node = min_heap->mh_nodes[min_heap->mh_size - 1];
	
    min_heap->mh_nodes[0] = last_node;
    min_heap->mh_pos[root->element] = min_heap->mh_size-1;
    min_heap->mh_pos[last_node->element] = 0;
 
   
    min_heap->mh_size--;
    mh_heapify(min_heap, 0);
 
    return root;
}



void mh_decreaseKey(struct t_MinH* min_heap, uint16_t v, uint16_t key)
{

    uint16_t it; 
	
	
	it = min_heap->mh_pos[v];
    min_heap->mh_nodes[it]->key = key;
 
 
    while (it && min_heap->mh_nodes[it]->key < min_heap->mh_nodes[(it - 1) / 2]->key)   {
        // zamien z rodzicem
        min_heap->mh_pos[min_heap->mh_nodes[it]->element] = (it-1)/2;
        min_heap->mh_pos[min_heap->mh_nodes[(it-1)/2]->element] = it;
        mh_swap(&min_heap->mh_nodes[it],  &min_heap->mh_nodes[(it - 1) / 2]);
		it = (it - 1) / 2;
    }
}