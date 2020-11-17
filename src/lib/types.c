#include "types.h"
#include <stdlib.h>

void delVec(Vector* vec)
{
    if (vec == NULL)
        return;

    free(vec->value);
    free(vec);
}

void delMat(Matrix* mat)
{
    if (mat == NULL)
        return;

    free(mat->value);
    free(mat);
}

void delVal(Val* val)
{
    if (val == NULL)
        return;

    free(val);
}
