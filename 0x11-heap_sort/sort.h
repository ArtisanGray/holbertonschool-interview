#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heap(int *arr, size_t size, size_t root);
void swap(int *arr, int *parent, int *child);

#endif
