#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_


#include "graph.h"






struct t_MinHNode
{
    int element;
    int key;
};
 

struct t_MinH
{
    int mh_size;     
    int mh_len;  
    int *mh_pos;     
    struct t_MinHNode **mh_nodes;
};


struct t_MinHNode* mh_newMinHNode(int v, int key);
struct t_MinH* mh_createMinH(int mh_len);
void mh_swap(struct t_MinHNode** a, struct t_MinHNode** b);
void mh_heapify(struct t_MinH* min_heap, int idx);
struct t_MinHNode* mh_cutMinHNode(struct t_MinH* min_heap);
void mh_decreaseKey(struct t_MinH* min_heap, int v, int key);





#endif /* MIN_HEAP_H_ */


