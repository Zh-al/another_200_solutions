class Solution {
public:

    string longestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1)
            return s;
        palindrome = s.substr(0, 1);
        for (int i = 1; i < s.length(); ++i) {
            expandPalindrome(i, i, s);
            expandPalindrome(i - 1, i, s);
            if (palindrome.length() > 2 * (s.length() - i)) {
                return palindrome;
            }
        }
        if (s[s.length() - 1] == s[s.length() - 2] && 2 > palindrome.size()){
            palindrome = s.substr(s.length() - 3, 2);
        }
        return palindrome;
    }
    
private:
    string palindrome;
    
    void expandPalindrome(int left, int right, string &s) {
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            --left;
            ++right;
        }    
        if (--right - ++left + 1 > (int)palindrome.length()) {
            palindrome = s.substr(left, right - left + 1);
        }   
    }
};
