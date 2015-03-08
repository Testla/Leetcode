#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(const int a, const int b) {
    return a > b ? b : a;
}

/*manacher*/
char *longestPalindrome(char *s) {
    /*match_length is a half including the middle*/
    int i, length = strlen(s), right_most = -1, middle_of_right_most, match_length[1000 * 2 + 1], end, ans, max = 0;
    char inserted[1000 * 2 + 1];
    for (i = 0, end = 0; i < length; ++i) {
        inserted[end++] = '\0';
        inserted[end++] = s[i];
    }
    inserted[end++] = '\0';
    for (i = 0; i < end; ++i) {
        if (i < right_most)
            match_length[i] = min(right_most - i + 1, match_length[2 * middle_of_right_most - i]);
        else
            match_length[i] = 1;
        while (match_length[i] <= i && i + match_length[i] < end && inserted[i - match_length[i]] == inserted[i + match_length[i]])
            ++match_length[i];
        if (match_length[i] + i - 1 > right_most) {
            right_most = match_length[i] + i - 1;
            middle_of_right_most = i;
        }
        if (match_length[i] - 1 > max) {
            max = match_length[i] - 1;
            ans = i;
        }
    }
    /*restore the palindrome substring*/
    char *result = (char *)malloc((max + 1) * sizeof(char));
    for (end = 0, i = ans - max; i < ans + max; ++i)
        if (inserted[i] != '\0')
            result[end++] = inserted[i];
    result[end] = '\0';
    return result;
}

int main(void) {
    char s[100];
    while (~scanf("%s", s))
        puts(longestPalindrome(s));
    return 0;
}

