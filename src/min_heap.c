#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"



struct t_MinHNode* mh_newMinHNode(uint16_t v, uint16_t key)
{
    struct t_MinHNode* tmp;
	tmp = malloc(sizeof(struct t_MinHNode));
    tmp->vertice = v;
    tmp->key = key;
    return tmp;
}
 

struct t_MinH* mh_create_MinH(uint16_t h_len)
{
    struct t_MinH* min_heap;
    min_heap = malloc(sizeof(struct t_MinH));
    min_heap->h_pos = malloc(h_len * sizeof(uint16_t));
    min_heap->h_size = 0;
    min_heap->h_len = h_len;
    min_heap->h_nodes = malloc(h_len * sizeof(struct t_MinHNode*));
    return min_heap;
}

void mh_swap(struct t_MinHNode** a, struct t_MinHNode** b)
{
    struct t_MinHNode* tmp;
	tmp = *a;
    *a = *b;
    *b = tmp;
}