#include <stdio.h>
#define PLUS(a, b) a + b
#define PRINT(a) printf (#a "mecro is");
int     main(void)
{
    int a;
    a = PLUS(4, 5);
    printf ("%d\n", a);
    PRINT(a);
}