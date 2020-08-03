//https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindromeHelper(s, false);
    }
    
    bool validPalindromeHelper(string s, bool deleted) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (deleted) 
                    return false;
                return validPalindromeHelper(s.substr(left, right - left), true) 
                    || validPalindromeHelper(s.substr(left + 1, right - left), true);
            }
            ++left, --right;
        }
        return true;
    }
};
