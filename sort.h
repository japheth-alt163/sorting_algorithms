#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/** prototypes given **/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** prototypes for the task **/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int len_list(listint_t *h);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void merge_arrays(int *array, int *temp, size_t start, size_t mid, size_t end);
void build_heap(int *array, size_t size);
void heapify(int *array, size_t size, int index);
void swap(int *a, int *b);
int is_power_of_two(size_t n);
void bitonic_compare(int *array, size_t size, int dir);
void bitonic_recursive_sort(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void hoare_quick_sort(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);

/* Sorting directions */
#define ASCENDING 1
#define DESCENDING 0

#endif
