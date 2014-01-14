#ifndef SET_H_
#define SET_H_



struct t_Set{
	int* set;
	int size;
};

struct t_Set* createSet(int size);

void addElement(struct t_Set *set, int element);

int exists(struct t_Set *v_set, int element);



#endif /* SET_H_ */