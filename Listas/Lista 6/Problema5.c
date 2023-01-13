#include <stdio.h>

int main()
{
	int x=10, y=20;
	int *p1;
	int *p2;

	p1 = &x;
	p2 = &y;
	(*p1)++;
	
	printf("x=%d, y=%d\n&x=%p, &y=%p\np1=%p, p2=%p\n*p1+*p2=%d, *(&x)=%d, &(*p2)=%p", x, y, &x, &y, p1, p2, (*p1)+(*p2), *(&x), &(*p2));

	return 0;
}