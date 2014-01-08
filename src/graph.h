#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdint.h>
#include <stdio.h>

struct t_Vertice{
	uint16_t dst_id; //vertice on the other side of the edge
    uint8_t  weight; //weight of the edge	
	struct t_Vertice *next;
} Vertice;

struct t_Edge{
	uint16_t src_id;
	uint16_t dst_id;
	uint8_t  weight;
};

typedef struct t_Vertice* Graph;



uint16_t getVerticesCount(char *filename);
Graph* createGraph(uint16_t size);
Graph* fillGraph(Graph* g, uint16_t size, char *filename);
void addEdge(Graph *g, uint16_t dst, uint16_t wght);
void showGraph(Graph* g, uint16_t size);



 




#endif /* GRAPH_H_ */

