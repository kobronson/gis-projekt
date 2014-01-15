#include "prim.h"
#include "set.h"
#include "debug.h"
#include <stdio.h>
#include<limits.h>


void prim(Graph *graph, int size){
	
	struct t_MinH* min_heap;
	struct t_MinHNode* mh_node;	
    int parent[size];   //wynik
	int weights[size];
    int key[size]; //klucze/wagi do pobrania minimalnej krawędzi     
	int i;
	int u,v2;
	struct t_Vertice* adjc_v;
 
	
    //kopiec - reprezentacja zbioru krawędzi
     min_heap = mh_createMinH(size);
 
    
	
	//inicjalizacja kopca binarnego - wagi sa na poczatku ustawiane na nieskonczonosc
 	for (i = 1; i < size; ++i){
        
		parent[i] = -1;		
        key[i] = INT_MAX;
		min_heap->mh_nodes[i] = mh_newMinHNode(i, key[i]);        
        min_heap->mh_pos[i] = i;
    }
	// ustawienie wartosci wierzholka 0 tak aby byl pobrany jako pierwszy
	key[0] = 0;
    min_heap->mh_nodes[0] = mh_newMinHNode(0, key[0]);
    min_heap->mh_pos[0]   = 0;
	
	min_heap->mh_size = size;
	
	// wezly ktore nie zostaly jeszcze dodane do MST
	while (min_heap->mh_size != 0)    {
        
		// znajdz wierzcholek o najmniejszej wadze
        mh_node = mh_cutMinHNode(min_heap);
        u = mh_node->element; // zapamietaj numer wiercholka
  
		adjc_v = graph[u];
        
		
		//przejdz przez sasiadow u i zaktualizuj ich wagi
		while (adjc_v != NULL){
		
		
		 v2 = adjc_v->dst_id;
		 
			//jesli v2 nie ma jeszcze w MST i waga v2-u jest mniejsza 
			//od obecnaje wartosci v to zaktualizuj wage i rodzica v			
            if ( min_heap->mh_pos[v2] < min_heap->mh_size && adjc_v->weight < key[v2]){
                key[v2] = adjc_v->weight;				
                parent[v2] = u;
				//zmniejsz wage
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
