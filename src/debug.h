#ifndef DEBUG_H_
#define DEBUG_H_

#include<stdio.h>

#define DBG_LINE printf("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);
#define DBG(...) printf( __VA_ARGS__)


#endif /* DEBUG_H_ */