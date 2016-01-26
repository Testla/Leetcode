#include <algorithm>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        /* f[n1, n2] = distance betwen first n1 characters of word1
         * and first n2 characters of word2 */
        int (*f)[l2 + 1] = (int (*)[l2 + 1])new int[(l1 + 1) * (l2 + 1)];
        for (int i = 0; i <= l2; ++i)
            f[0][i] = i;
        for (int i = 1; i <= l1; ++i)
            f[i][0] = i;
        for (int i = 1; i <= l1; ++i)
            for (int j = 1; j <= l2; ++j)
                f[i][j] = std::min(
                    f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]),
                    std::min(f[i][j - 1], f[i - 1][j]) + 1
                );
        return f[l1][l2];
    }
};
