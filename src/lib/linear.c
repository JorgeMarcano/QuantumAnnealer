#include "linear.h"
#include <stdlib.h>

Vector* matrixVector(Matrix* matrix, Vector* vector)
{
    if (matrix->n != vector->m)
        return NULL;

    Vector* returnVec = malloc(sizeof(Vector));
    returnVec->m = matrix->m;
    returnVec->value = malloc(returnVec->m * sizeof(Size));

    Size tempOffset = 0;
    for (Size i = 0; i < returnVec->m; i++)
    {
        returnVec->value[i] = 0;
        tempOffset = i * matrix->n;
        for (Size j = 0; j < vector->m; j++)
            returnVec->value[i] += matrix->value[tempOffset + j] * vector->value[j];
    }

    return returnVec;
}

Val* dot(Vector* vector1, Vector* vector2)
{
    Size size = vector1->m;
    if (size != vector2->m)
        return NULL;

    Val* returnVal = malloc(sizeof(Val));

    *returnVal = 0;

    for (Size i = 0; i < size; i++)
        returnVal += vector1->value[i] * vector2->value[i];

    return returnVal;
}

Matrix* transpose(Matrix* matrix)
{
    Size row = matrix->n;
    Size col = matrix->m;

    Matrix* returnMat = malloc(sizeof(Matrix));
    returnMat->value = malloc(row * col * sizeof(Val));
    returnMat->n = matrix->m;
    returnMat->m = matrix->n;

    for (Size i = 0; i < row * col; i++)
        returnMat->value[(i % row) * col + (i / row)] = matrix->value[i];

    return returnMat;
}

Val* xQx(Matrix* q, Vector* x)
{
    Size size = x->m;
    if (q->m != size || q->n != size)
        return NULL;

    Val* returnVal = malloc(sizeof(Val));
    *returnVal = 0;

    Size tempOffset = 0;
    Val tempVal = 0;
    for (Size i = 0; i < size; i++)
    {
        tempVal = 0;
        tempOffset = i * size;
        for (Size j = 0; j < size; j++)
            tempVal += q->value[tempOffset + j] * x->value[j];

        *returnVal += tempVal * x->value[i];
    }

    return returnVal;
}
