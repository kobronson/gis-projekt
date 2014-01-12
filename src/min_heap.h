#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <stdint.h>
#include "graph.h"






struct t_MinHNode
{
    uint16_t element;
    uint16_t key;
};
 

struct t_MinH
{
    uint16_t h_size;     
    uint16_t h_len;  
    uint16_t *h_pos;     
    struct t_MinHNode **h_nodes;
};


struct t_MinHNode* mh_newMinHNode(uint16_t v, uint16_t key);
struct t_MinH* mh_createMinH(uint16_t h_len);
void mh_swap(struct t_MinHNode** a, struct t_MinHNode** b);
void mh_heapify(struct t_MinH* min_heap, uint16_t idx);
struct t_MinHNode* mh_cutMinHNode(struct t_MinH* min_heap);
void mh_decreaseKey(struct t_MinH* min_heap, uint16_t v, uint16_t key);





#endif /* MIN_HEAP_H_ */


