#ifndef LINEAR_H
#define LINEAR_H

#include "types.h"

Vector* matrixVector(Matrix* matrix, Vector* vector);
Val* dot(Vector* vector1, Vector* vector2);

Matrix* transpose(Matrix* matrix);

Val* xQx(Matrix* q, Vector* x);

#endif
