#ifndef DMATRIX_H
#define DMATRIX_H

typedef struct matrix Matrix;
typedef struct array Array;

struct array
{
	float element;
	Array* next;
	Array* previous;
};

struct matrix
{
	int width;
	int height;
	Array* root;
};

Array* newArray(){
	Array* array = NULL;
	return array;
}

Matrix* newMatrix(){
	Matrix* matrix;
	matrix->width = 0;
	matrix->width = 0;
	matrix->root = newArray();
	return matrix;
}

#endif