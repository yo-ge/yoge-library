#include <stdio.h>
#include <stdlib.h>

#define NITEMS(array) (sizeof array / sizeof array[0])

void swap(int nums[], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

/* Bubble sorts NUMS indexed 0, 1, ... n - 1. */
void bubble_sort(int nums[], int size) {
    int i, j, swapped;
    for (i = 0; i < size; ++i) {
        swapped = 0;
        for (j = 0; j < size - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums, j, j + 1);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int samples[] = {20, 423, 2143213, 3241, 2342,
                    43124, 3214, 1111, 222, 222,
                    233333, };

    bubble_sort(samples, NITEMS(samples));

    int i;
    for (i = 0; i < NITEMS(samples); ++i) {
        printf("%d%c", samples[i], i == NITEMS(samples) - 1 ? '\n' : ' ');
    }

    return 0;
}