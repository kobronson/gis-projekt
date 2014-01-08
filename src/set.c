#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "graph.h"


struct t_VSet* createSet(uint16_t size)
{
	struct t_VSet *new_set;
	new_set = malloc( sizeof(struct t_VSet));
	new_set->size=0;
	new_set->set = malloc(size * sizeof(uint16_t));
	
	return new_set;
}

void addElement(struct t_VSet *v_set, uint16_t element)
{
	v_set->set[v_set->size] = element;
	v_set->size++;
}

uint16_t exists(struct t_VSet *v_set, uint16_t element)
{
	uint16_t i;
	for(i=0; i < v_set->size; i++)
	{
		if(v_set->set[i] == element) 
		{
			return 1;
		}
	}
	return 0;
}

struct t_ESet* createESet(uint16_t size){

	struct t_ESet *new_set;
	new_set = malloc( sizeof(struct t_ESet));
	new_set->size=0;
	new_set->eset = malloc(size * sizeof(struct t_Edge));
	
	return new_set;

}




void addESet(struct t_ESet *e_set, struct t_Edge* element)
{
	struct t_Edge* tmp;
	tmp = &e_set->eset[e_set->size];
	tmp->src_id = element->src_id;
	tmp->dst_id = element->dst_id;
	tmp->weight = element->weight;
	e_set->size++;

}