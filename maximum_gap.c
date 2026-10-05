#include <stdlib.h>
#include <stdbool.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    int min_val = nums[0];
    int max_val = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min_val = MIN(min_val, nums[i]);
        max_val = MAX(max_val, nums[i]);
    }
    if (min_val == max_val) {
        return 0;
    }
    int bucket_size = MAX(1, (max_val - min_val) / (numsSize - 1));
    int bucket_count = (max_val - min_val) / bucket_size + 1;
    int* bucket_min = (int*)malloc(sizeof(int) * bucket_count);
    int* bucket_max = (int*)malloc(sizeof(int) * bucket_count);
    bool* bucket_has_element = (bool*)calloc(bucket_count, sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - min_val) / bucket_size;
        if (!bucket_has_element[idx]) {
            bucket_min[idx] = nums[i];
            bucket_max[idx] = nums[i];
            bucket_has_element[idx] = true;
        } else {
            bucket_min[idx] = MIN(bucket_min[idx], nums[i]);
            bucket_max[idx] = MAX(bucket_max[idx], nums[i]);
        }
    }
    int max_gap = 0;
    int previous_max = min_val;
    for (int i = 0; i < bucket_count; i++) {
        if (!bucket_has_element[i]) {
            continue;
        }
        max_gap = MAX(max_gap, bucket_min[i] - previous_max);
        previous_max = bucket_max[i];
    }
    free(bucket_min);
    free(bucket_max);
    free(bucket_has_element);
    return max_gap;
}