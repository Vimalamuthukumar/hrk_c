#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int compareIntervals(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 1) {
        *returnSize = intervalsSize;
        *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
        for (int i = 0; i < intervalsSize; i++) {
            (*returnColumnSizes)[i] = 2;
        }
        return intervals;
    }
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);
    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    int count = 0;
    result[count] = (int*)malloc(sizeof(int) * 2);
    result[count][0] = intervals[0][0];
    result[count][1] = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[count][1]) {
            result[count][1] = MAX(result[count][1], intervals[i][1]);
        } else {
            count++;
            result[count] = (int*)malloc(sizeof(int) * 2);
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
        }
    }
    *returnSize = count + 1;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}