#include <stdio.h>
#include <stdlib.h>

/**
 * Quick-sort implemetation from The Practice of Programming.
 */

#define NELEM(array) (sizeof array / sizeof array[0])

void swap(int array[], int i, int j);

/* Quick-sorts array indexed of 0, 1, ... n - 1. */
void quick_sort(int array[], int n) {
    if (n <= 1) {
        /* Nothing to do. */
        return;
    }
    /* Randomly chooses a pivot and puts it to the front. */
    swap(array, 0, rand() % n);
    int last = 0, i;    /* last: the last element < pivot */
    for (i = 1; i < n; ++i) {
        if (array[i] < array[0]) {
            swap(array, i, ++last);
        }
    }
    /* Restores the pivot. */
    swap(array, 0, last);
    /* Recursively sorts the two parts. */
    quick_sort(array, last);
    quick_sort(array + last + 1, n - last - 1);
}

/* Swaps array[i] and array[j]. */
void swap(int array[], int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/* Tests. */
int main() {
    int sample[] = {20, 423, 2143213, 3241, 2342,
                    43124, 3214, 1111, 222, 222,
                    233333, };

    quick_sort(sample, NELEM(sample));

    int i;
    for (i = 0; i < NELEM(sample); ++i) {
        printf("%d%c", sample[i], i == NELEM(sample) - 1 ? '\n' : ' ');
    }

    return 0;
}
