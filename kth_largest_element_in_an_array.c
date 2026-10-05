#include <stdlib.h>
#include <string.h>
int findKthLargest(int* nums, int numsSize, int k) {
    int count[20001] = {0};  
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 10000]++;
    }
    int current_k = 0;
    for (int i = 20000; i >= 0; i--) {
        current_k += count[i];
        if (current_k >= k) {
            return i - 10000;
        }
    }
    return -1;
}