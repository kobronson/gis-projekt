#include "kruskal.h"
#include "set.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>



int compareEdges(const void* edge_1, const void* edge_2)
{
    struct t_Edge* e1 = (struct t_Edge*)edge_1;
    struct t_Edge* e2 = (struct t_Edge*)edge_2;
    return e1->weight > e2->weight;
}

EGraph* kruskal(EGraph *egraph){
	
	Graph *trees;
	
	
	
	trees = malloc(egraph->v_count*sizeof(Graph));
	qsort(egraph->edges, egraph->e_count, sizeof(egraph->edges[0]), compareEdges);
	
	return egraph;


}