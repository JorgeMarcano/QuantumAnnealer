#include "lib/linear.h"
#include "lib/types.h"
#include "lib/search.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Matrix* mat = malloc(sizeof(Matrix));
    mat->m = 2;
    mat->n = 2;
    mat->value = malloc(4 * sizeof(Val));
    mat->value[0] = -4;
    mat->value[1] = 4;
    mat->value[2] = 0;
    mat->value[3] = -3;

    Vector* vec = searchSpace(mat);

    Val min = 0;
    Size indexMin = 0;
    for (Size i = 0; i < vec->m; i++)
    {
        printf("0x%x: %d\n", i, vec->value[i]);

        if (vec->value[i] < min)
        {
            min = vec->value[i];
            indexMin = i;
        }
    }

    printf("\nThe minimum found was in state 0x%x, with a value of %d\n", indexMin, min);

    delVec(vec);
    delMat(mat);

    return 1;
}
