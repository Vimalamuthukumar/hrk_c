#include <string.h>
#include <stdlib.h>
void expand(const char* s, int len, int left, int right, int* start, int* max_len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    int current_len = right - left - 1;
    if (current_len > *max_len) {
        *max_len = current_len;
        *start = left + 1;
    }
}
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 1) return "";
    int start = 0;
    int max_len = 0;
    for (int i = 0; i < len; i++) {
        expand(s, len, i, i, &start, &max_len);
        expand(s, len, i, i + 1, &start, &max_len);
    }
    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';
    return result;
}