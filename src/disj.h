#ifndef DISJ_H_
#define DISJ_H_

#include <stdint.h>




/*Disjoint data set - warunek nie moze byc cykli w grafie*/

struct disj_set{
	uint16_t parent;
	uint16_t rnk;
};

 

int compareEdges(const void* edge_1, const void* edge_2);
uint16_t disj_find(struct disj_set* ssets, uint16_t vertice);



#endif /* DISJ_H_ */