//https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        bool hasOdd = false;
        int result = 0;
        for (auto [k, v] : count) {
            result += v / 2 * 2;
            if (v % 2) hasOdd = true;
        }
        if (hasOdd) ++result;
        return result;
    }
};
