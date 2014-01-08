#ifndef SET_H_
#define SET_H_

#include <stdint.h>
#include "graph.h"

struct t_VSet{
	uint16_t* set;
	uint16_t size;
};



struct t_VSet* createSet(uint16_t size);

void addElement(struct t_VSet *set, uint16_t element);

uint16_t exists(struct t_VSet *v_set, uint16_t element);


struct t_ESet{
	struct t_Edge* eset;
	uint16_t size;
};

struct t_ESet* createESet(uint16_t size);
void addESet(struct t_ESet *set, struct t_Edge* element);



#endif /* SET_H_ */