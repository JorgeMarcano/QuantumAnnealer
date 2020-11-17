#include "linear.h"
#include "types.h"
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

    Vector* vec = malloc(sizeof(Vector));
    vec->value = malloc(2 * sizeof(Val));
    vec->m = 2;
    Val* tempVal = NULL;
    Val min = 0;
    for (Size i = 0; i < 4; i++)
    {
        vec->value[0] = i / 2;
        vec->value[1] = i % 2;

        tempVal = xQx(mat, vec);
        printf("%d: %d\n", i, *tempVal);

        if (*tempVal < min)
            min = *tempVal;

        delVal(tempVal);
    }

    printf("\nThe minimum found was %d\n", min);

    delVec(vec);
    delMat(mat);

    return 1;
}
