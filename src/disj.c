#include <stdio.h>
#include <stdlib.h>
#include"disj.h"

/*Znajdowanie korzenia drzewa - wykrywanie cykli*/
int disj_find(struct disj_set* ssets, int vertice)
{
    //znajdz korzen drzewa
    if (ssets[vertice].parent != vertice)
        ssets[vertice].parent = disj_find(ssets, ssets[vertice].parent);
 
    return ssets[vertice].parent;	
}


/*Polaczenie zbiorow v1 i v2*/
void disj_union(struct disj_set* ssets, int v1, int v2)
{
    int v1_root;
    int v2_root; 
	v1_root	= disj_find(ssets, v1);
	v2_root = disj_find(ssets, v2);
    // dolacz drzewo o mniejszej randze do korzenia drzewa o wyzszej randze
    if (ssets[v1_root].rnk < ssets[v2_root].rnk)
        ssets[v1_root].parent = v2_root;
    else if (ssets[v1_root].rnk > ssets[v2_root].rnk)
        ssets[v2_root].parent = v1_root;
 
    // jesli rangi sa takie same
    else
    {
        ssets[v2_root].parent = v1_root;
        ssets[v1_root].rnk++;
    }
}