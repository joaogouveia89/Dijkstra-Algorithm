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

Array* newArray()
{
	Array* array = NULL;
	return array;
}

Array* array_add(Array* root, float element){
	Array* aux = (Array*) malloc(sizeof(Array));

	aux->element = element;
	aux->next = NULL;
	aux->previous = NULL;

	if(root == NULL){
		aux->next = aux->previous = aux;
		root = aux;
	}else{
		Array* last = root->previous;
		aux->next = root;
		root->previous = aux;
		aux->previous = last;
		last->next = aux;
	}

	return root;
}

Matrix* newMatrix()
{
	Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
	matrix->width = 0;
	matrix->height = 0;
	matrix->root = newArray();
	return matrix;
}

Matrix* add(Matrix* matrix, char element)
{
	if(matrix == NULL){
		return matrix;
	}else{
		float value = getMatrixValue(element);
		matrix->root = array_add(matrix->root, value);
	}
	return matrix;
}

#endif