#include "prim.h"
#include "set.h"
#include "debug.h"
#include <stdio.h>
#include<limits.h>


Graph* prim(Graph *graph, int size){
	
	struct t_MinH* min_heap;
	struct t_MinHNode* mh_node;	
    int parent[size];   //wynik
	int weights[size];
    int key[size];      
	int i;
	int u,v2;
	struct t_Vertice* adjc_v;
 
	
    
     min_heap = mh_createMinH(size);
 
    
	
	// inicjalizacja struktur danych
	
 	for (i = 1; i < size; ++i){
        
		parent[i] = -1;		
        key[i] = INT_MAX;
		min_heap->mh_nodes[i] = mh_newMinHNode(i, key[i]);        
        min_heap->mh_pos[i] = i;
    }
	key[0] = 0;
    min_heap->mh_nodes[0] = mh_newMinHNode(0, key[0]);
    min_heap->mh_pos[0]   = 0;
	
	min_heap->mh_size = size;
	
	while (min_heap->mh_size != 0)    {
        // znajdz wierzcholek o najmniejszym kluczcu
        mh_node = mh_cutMinHNode(min_heap);
        u = mh_node->element; // zapamietaj id
  
		adjc_v = graph[u];
        
		while (adjc_v != NULL){
		
		
		 v2 = adjc_v->dst_id;
       
            if ( min_heap->mh_pos[v2] < min_heap->mh_size && adjc_v->weight < key[v2]){
                key[v2] = adjc_v->weight;				
                parent[v2] = u;
                mh_decreaseKey(min_heap, v2, key[v2]);
            }
            adjc_v = adjc_v-> next;
        }
		
	}
#ifdef DEBUG
	for ( i = 1; i < size; ++i)
        printf(" (%d %d)-%d\n", i, parent[i],key[i]);
#endif
		
		
	
}
