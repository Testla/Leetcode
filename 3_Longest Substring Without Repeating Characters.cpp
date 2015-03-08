class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_appear[256], length = s.size(), start, i, ans = 0;
        memset(last_appear, -1, sizeof(last_appear));
        for (i = 0, start = 0; i < length; ++i) {
            if (last_appear[s[i]] >= start)
                start = last_appear[s[i]] + 1;
            else
                ans = std::max(ans, i + 1 - start);
            last_appear[s[i]] = i;
        }
        return ans;
    }
};

