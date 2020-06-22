class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars;
        int max = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (chars.count(s[i])) {
                int j = i - chars.size();
                if (chars.size() > max) {
                    max = chars.size();
                }
                while (s[j] != s[i]) {
                    chars.erase(s[j++]);
                }
            } else {
                chars.insert(s[i]);
            }
        }
        return max > chars.size() ? max : chars.size();
    }
};
