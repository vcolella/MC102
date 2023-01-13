#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 5;

	int *v;
	v = (int*)malloc(2*sizeof(int));

	*v = 10;
	v[1]=30;

	printf("&x=%p x=%d\n&v=%p v=%d\n&v[1]=%p v[1]=%d\n\n", &x, x, v, *v, &v[1], v[1]);
	free(v);
	v = NULL;

	return 0;
}