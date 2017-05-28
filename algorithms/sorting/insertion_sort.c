#include <stdio.h>
#include <stdlib.h>

#define NITEMS(array) (sizeof array / sizeof array[0])

/* Insertion-sorts NUMS indexed 0, 1, ..., size - 1.*/
void insertion_sort(int nums[], int size) {
    int i, j, insertee;
    for (i = 1; i < size; ++i) {
        insertee = nums[i];
        for (j = i - 1; j >= 0 && insertee < nums[j]; --j) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = insertee;
    }
}

/* Driver. */
int main() {
    int samples[] = {20, 423, 2143213, 3241, 2342,
                    43124, 3214, 1111, 222, 222,
                    233333, };

    insertion_sort(samples, NITEMS(samples));

    int i;
    for (i = 0; i < NITEMS(samples); ++i) {
        printf("%d%c", samples[i], i == NITEMS(samples) - 1 ? '\n' : ' ');
    }

    return 0;
}