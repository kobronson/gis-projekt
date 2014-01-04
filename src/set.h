#ifndef SET_H_
#define SET_H_

#include <stdint.h>

struct t_Set{
	uint16_t* set;
	uint16_t size;
};

struct t_Set* createSet(uint16_t size);

void addElement(struct t_Set *set, uint16_t element);

uint16_t exists(struct t_Set *v_set, uint16_t element);



#endif /* SET_H_ */