
#include <stdlib.h>
#include <string.h>
#include "set.h"


struct t_Set* createSet(uint16_t size)
{
	struct t_Set *new_set;
	new_set = malloc( sizeof(struct t_Set));
	new_set->size=0;
	new_set->set = malloc(size * sizeof(uint16_t));
	
	return new_set;
}

void addElement(struct t_Set *v_set, uint16_t element)
{
	v_set->set[v_set->size] = element;
	v_set->size++;
}