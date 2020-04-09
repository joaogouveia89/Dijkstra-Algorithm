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

Array* array_dealloc(Array* root){
	Array* last = root->next;
	Array* current = root->next->next;
	while(current != root){
		free(last);
		last = current;
		current = current->next;
	}
	free(root);
	return NULL;
}

void array_print_debug(Array* root){
	if(root != NULL){
		Array* aux = root->next;
		printf("%f, ", root->element);
		while(aux->next != root){
			printf("%f, ", aux->element);
			aux = aux->next;
		}
		printf("%f\n", aux->element);
	}
}

Matrix* newMatrix()
{
	Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
	matrix->width = 0;
	matrix->height = 0;
	matrix->root = newArray();
	return matrix;
}

Matrix* add(Matrix* matrix, float element)
{
	if(matrix == NULL){
		return matrix;
	}else{
		matrix->root = array_add(matrix->root, element);
	}
	return matrix;
}

Matrix* matrix_dealloc(Matrix* matrix){
	if(matrix != NULL){
		matrix->root = array_dealloc(matrix->root);
	}
	free(matrix);
	return NULL;
}

Matrix* set_matrix_width(Matrix* root, int width){
	root->width = width;
	return root;
}

Matrix* set_matrix_height(Matrix* root, int height){
	root->height = height;
	return root;
}

float get(Matrix* root, int line, int column){
	int arrayPosition = (line * root->width) + column;
	Array* aux = root->root;
	int idx = 0;
	while(idx < arrayPosition){
		aux = aux->next;
		idx++;
	}
	return aux->element;
}

#endif