#include <stdio.h>

/**
 * Selection sort algorithm implementation.
 */

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

/* Main algorithm. */
void selection_sort(int array[], int size) {
    int i, j;
    for (i = 0; i < size; ++i) {
        int min_index = i;
        for (j = i; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(array + i, array + min_index);
    }
}

/* Test */
int main() {
    int array[] = {8, 2, 4, 8, 1, 22, 3, 44, 5, 6, 2, -1, 0};
    int size = sizeof array / sizeof array[0];
    selection_sort(array, size);
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d%c", array[i], i == size - 1 ? '\n' : ' ');
    }
    return 0;
}