#include "kruskal.h"
#include "set.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include "disj.h"




int compareEdges(const void* edge_1, const void* edge_2)
{
    struct t_Edge* e1 = (struct t_Edge*)edge_1;
    struct t_Edge* e2 = (struct t_Edge*)edge_2;
    return e1->weight > e2->weight;
}

EGraph* kruskal(EGraph *egraph){
	
	Graph *trees;
	struct disj_set *ssets;
	long int i,edg;
	int v1,v2;
	struct t_Edge *curr_edge;
	EGraph *res_graph = createEGraph(egraph->v_count, egraph->v_count - 1);
	
	
	
	/*disj-set*/
	ssets = malloc( egraph->v_count * sizeof(struct disj_set) );
	for (i = 0; i < egraph->v_count; ++i) {
        ssets[i].parent = i;
        ssets[i].rnk = 0;
    }
	qsort(egraph->edges, egraph->e_count, sizeof(egraph->edges[0]), compareEdges);
	
	
	i=0;
	edg=0;
	
	while(edg < egraph->v_count -1){
	
		curr_edge = &egraph->edges[i++];
		v1 = disj_find(ssets,curr_edge->src_id);
		v2 = disj_find(ssets,curr_edge->dst_id);
		if(v1 != v2){
			disj_union(ssets,v1,v2);
			res_graph->edges[edg++] = *curr_edge;		
		}
	}
	
	
	
	return res_graph;


	
}



/* 
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%lu -- %lu == %lu\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    return; */