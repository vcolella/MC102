#include <stdio.h>
/*Para o RA 157462, D = 2,
e o programa imprime
x = 3, y = 1
x = 1, y = 11
x = 0, y = 111
x = 11, y = 11
x = 11, y = 1
x = 1, y = 0 */

int main()
{
    int D = 2;
    int x = 5+D, y = 0;
    do
    {
        y = (x % 2) + 10 * y;
        x = x / 2;
        printf("x = %d, y = %d\n", x, y );
    }
    while (x != 0);
    while (y != 0)
    {
        x = y % 100;
        y = y / 10;
        printf("x = %d, y = %d\n", x, y );
    }
}
