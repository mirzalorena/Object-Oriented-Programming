#include "array.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Arrays* createArrays(int capacity)
{
	Arrays* arr = (Arrays*)malloc(sizeof(Arrays));
	// make sure that the space was allocated
	if (arr == NULL)
		return NULL;
	//we define the capacity of the array
	arr->capacity = capacity;
	arr->length = 0;

	// allocate space for the elements
	arr->elems = (Element*)malloc(capacity * sizeof(Element));
	if (arr->elems == NULL)
		return NULL;
	return arr;
}

void addToArray(Arrays* arr, Element t)
{
	//if we don't have an array we can't add to it
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	//we got to the maximum number of elements so we resize our array
	if (arr->length == arr->capacity)
		resize(arr);
	//we increase the lenght and add the element t at the end of the dynamic array
	arr->elems[arr->length++] = t;
}

void exchange(Arrays* arr, int i, int j)
{
	Map *m = createMap("Null", "null", 1,1);
	m = arr->elems[i];
	arr->elems[i] = arr->elems[j];
	arr->elems[j] = m;
}

void delete(Arrays* arr, int pos)
{
	//if we don't have an array we can't delete it
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	//if we've got an invalid position we can't do anything
	if (pos < 0 || pos >= arr->length)
		return;
	//we delete the country by overwritting all the elements starting with this Country
	//and replaced by the right one
	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];
	//we just got rid of a country
	arr->length--;
}

int getLength(Arrays* arr)
{
	if (arr == NULL)
		return -1;
	return arr->length;
}