#include "search.h"
#include "linear.h"
#include "stdlib.h"

Size power(Size a, Size b);

Vector* searchSpace(Matrix* mat)
{
    Size size = mat->m;
    Size qubits = size;

    size = power(2, size);

    Vector* returnVec = malloc(sizeof(Vector));
    returnVec->m = size;
    returnVec->value = malloc(size * sizeof(Val));

    Vector* vec = malloc(sizeof(Vector));
    vec->value = malloc(qubits * sizeof(Val));
    vec->m = qubits;

    Val* tempVal = NULL;
    Val min = 0;

    for (Size i = 0; i < size; i++)
    {
        for (Size j = 0; j < qubits; j++)
            vec->value[j] = (i >> (qubits - j - 1)) % 2;

        tempVal = xQx(mat, vec);
        returnVec->value[i] = *tempVal;

        delVal(tempVal);
    }

    delVec(vec);

    return returnVec;
}

Size power(Size a, Size b)
{
    Size returnSize = 1;

    for (Size i = 0; i < b; i++)
        returnSize *= a;

    return returnSize;
}
