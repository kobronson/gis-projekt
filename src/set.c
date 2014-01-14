#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"


struct t_Set* createSet(int size)
{
	struct t_Set *new_set;
	new_set = malloc( sizeof(struct t_Set));
	new_set->size=0;
	new_set->set = malloc(size * sizeof(int));
	
	return new_set;
}

void addElement(struct t_Set *v_set, int element)
{
	v_set->set[v_set->size] = element;
	v_set->size++;
}

int exists(struct t_Set *v_set, int element)
{
	int i;
	for(i=0; i < v_set->size; i++)
	{
		if(v_set->set[i] == element) 
		{
			return 1;
		}
	}
	return 0;
}