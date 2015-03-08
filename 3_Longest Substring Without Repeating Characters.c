#define max(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char *s) {
    int last_appear[256], length = strlen(s), start, i, ans = 0;
    memset(last_appear, -1, sizeof(last_appear));
    for (i = 0, start = -1; i < length; ++i) {
        if (last_appear[s[i]] > start)
            start = last_appear[s[i]];
        else
            ans = max(ans, i - start);
        last_appear[s[i]] = i;
    }
    return ans;
}

