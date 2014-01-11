#include <stdio.h>
#include <stdlib.h>
#include"disj.h"

uint16_t disj_find(struct disj_set* ssets, uint16_t vertice)
{
    //find root of the tree
    if (ssets[vertice].parent != vertice)
        ssets[vertice].parent = disj_find(ssets, ssets[vertice].parent);
 
    return ssets[vertice].parent;	
}

void disj_union(struct disj_set* ssets, uint16_t v1, uint16_t v2)
{
    uint16_t v1_root;
    uint16_t v2_root; 
	v1_root	= disj_find(ssets, v1);
	v2_root = disj_find(ssets, v2);
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (ssets[v1_root].rnk < ssets[v2_root].rnk)
        ssets[v1_root].parent = v2_root;
    else if (ssets[v1_root].rnk > ssets[v2_root].rnk)
        ssets[v2_root].parent = v1_root;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        ssets[v2_root].parent = v1_root;
        ssets[v1_root].rnk++;
    }
}