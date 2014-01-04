#include "prim.h"
#include "set.h"
#include <stdio.h>


Graph* prim(Graph *graph, uint16_t size)
{
	Graph* e_new;
	struct t_Set *v_new;
	uint16_t i;
	struct t_Edge* tmp;
	
	/*Prim init*/
	v_new = createSet(size);
	addElement(v_new, 1);
	
	while(v_new->size != size){
		
		for(i=0; i < v_new->size;i++){
			
			
			tmp = graph[v_new->set[i]];
			while(tmp)
			{
				
				tmp=tmp->next;
			}
		
		}
	}
	
	return NULL;
	
}
