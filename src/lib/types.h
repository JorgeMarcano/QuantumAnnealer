#ifndef TYPES_H
#define TYPES_H

typedef int Size;
typedef int Val;

typedef struct Matrix
{
    Val* value;

    Size m;
    Size n;

} Matrix;

typedef struct Vector
{
    Val* value;

    Size m;
} Vector;

void delVec(Vector* vec);
void delMat(Matrix* mat);
void delVal(Val* val);

#endif
