#include <stdio.h>
#include <stdlib.h>

void main(){

	int x;
	int f() {
		printf("f() is called\n");
		return 1;
	} ;
       f();
       printf("x=%d\n",x);
}
