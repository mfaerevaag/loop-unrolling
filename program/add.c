#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void MAGIC_FUNC (int *a, int *b)
{
    int x, y;

    x = *a;
    x = x + 7;
    *a = x;

    y = *b;
    y = y + 7;
    *b = y;
}

int main(void)
{
    uint64_t t0, t1;
    int *a, *b;

    a = (int *) malloc(sizeof(int));
    b = (int *) malloc(sizeof(int));

    *a = 33;
    *b = 66;

    t0 = rdtsc();
    MAGIC_FUNC (a, b);
    t1 = rdtsc();

    printf("%zu\n", t1 - t0);

    return 0;
}
