#include "kruskal.h"
#include "set.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include "disj.h"



/*porownanie do quick sort*/
int compareEdges(const void* edge_1, const void* edge_2)
{
    struct t_Edge* e1 = (struct t_Edge*)edge_1;
    struct t_Edge* e2 = (struct t_Edge*)edge_2;
    return e1->weight > e2->weight;
}

/*Algorytm Kruskala
egraph - graf w reprezentacji krawedziowej
*/
EGraph* kruskal(EGraph *egraph){
	
	Graph *trees;
	struct disj_set *ssets;
	long int i,edg;
	int v1,v2;
	struct t_Edge *curr_edge;
	EGraph *res_graph = createEGraph(egraph->v_count, egraph->v_count - 1);
	
	//sortuj wierzcholki
	qsort(egraph->edges, egraph->e_count, sizeof(egraph->edges[0]), compareEdges);
	
	
	//disj-set - V jednoelementowych podzbiorow
	
	ssets = malloc( egraph->v_count * sizeof(struct disj_set) );
	for (i = 0; i < egraph->v_count; ++i) {
        ssets[i].parent = i;
        ssets[i].rnk = 0;
    }
	
	
	
	i=0;
	edg=0;
	
	//wykonuj dopoki ilosc wierzcholkow nie bedzie rowna ilosci ktora powinno miec MST
	while(edg < egraph->v_count -1){
	
		//wybierz najmniejszy wierzcholek
		curr_edge = &egraph->edges[i++];
		v1 = disj_find(ssets,curr_edge->src_id);
		v2 = disj_find(ssets,curr_edge->dst_id);
		// jesli nie ma cyklu to dodaj wierzcholek do MST, jesli jest odrzuc
		if(v1 != v2){
			//polacz
			disj_union(ssets,v1,v2);
			res_graph->edges[edg++] = *curr_edge;		
		}
	}
	
	
	
	return res_graph;


	
}