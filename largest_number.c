#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b) {
    char s1[12], s2[12];
    char s1s2[24], s2s1[24];  
    sprintf(s1, "%d", *(const int *)a);
    sprintf(s2, "%d", *(const int *)b);  
    strcpy(s1s2, s1);
    strcat(s1s2, s2);   
    strcpy(s2s1, s2);
    strcat(s2s1, s1);  
    return strcmp(s2s1, s1s2); 
}
char *largestNumber(int *nums, int numsSize) {
    if (numsSize == 0) return "";
    qsort(nums, numsSize, sizeof(int), compare);
    if (nums[0] == 0) {
        char *zeroResult = (char *)malloc(2 * sizeof(char));
        strcpy(zeroResult, "0");
        return zeroResult;
    }
    char *result = (char *)malloc(numsSize * 12 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        char temp[12];
        sprintf(temp, "%d", nums[i]);
        strcat(result, temp);
    }
    return result;
}