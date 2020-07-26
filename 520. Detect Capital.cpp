//https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) return true;
        bool firstCapital = isCapital(word[0]);
        bool secondCapital = isCapital(word[1]);
        if (secondCapital && !firstCapital) return false;
        for (int i = 2; i < word.size(); ++i) {
            // check that all capital or all lowercase, exclude first letter
            if (!(secondCapital == isCapital(word[i]))) return false;
        }
        return true;
    }
    
    bool isCapital(char c) {
        return c >= 'A' && c <= 'Z';
    }
};
