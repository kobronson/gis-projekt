#include "prim.h"
#include "set.h"
#include "debug.h"
#include <stdio.h>


Graph* prim(Graph *graph, uint16_t size)
{
	Graph* e_new;
	struct t_Set *v_new;
	uint16_t i,src_id;
	uint8_t wght;
	struct t_Vertice *tmp, *min_e;
	
	
	/*Prim init*/
	v_new = createSet(size);
	addElement(v_new, 0);
	e_new = createGraph (size);
	while(v_new->size != size){
		
		wght = UINT8_MAX;
		
		/* Find min weight edge  (u,v)*/
		for(i=0; i < v_new->size;i++){
			
			
			tmp = graph[v_new->set[i]];
			while(tmp){   
				// v is not in V_new
				if(!exists(v_new,tmp->dst_id)) {
					
					if(tmp->weight < wght) {
						min_e = tmp;
						wght = min_e->weight;
						src_id = v_new->set[i]; 						
					}
				}

				tmp=tmp->next;				
			}
			
		
		}
		
		addElement(v_new, min_e->dst_id);
		addVertice(&(e_new[src_id]), min_e->dst_id, min_e->weight);
		addVertice(&(e_new[min_e->dst_id]), src_id, min_e->weight);
	}
	
	return e_new;
	
}
