#include <stdio.h>

#define NITEMS(array) (sizeof array / sizeof array[0])

/* Binary-searches the QUERY in the NUMS array in size SIZE.
 * Returns the query's index in the NUMS if found, otherwise -1. */
int binary_search(int query, int nums[], int size) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == query) {
            return mid;
        }
        if (nums[mid] < query) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 6, 7, 10, 22};
    int queries[] = {1, 4, 5, 22, 0, 100};
    int i;
    for (i = 0; i < NITEMS(queries); ++i) {
        printf("search result of %d in nums: %d\n",
            queries[i], binary_search(queries[i], nums, NITEMS(nums)));
    }
}