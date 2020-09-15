//https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = (int)s.size() - 1;
        int count = 0;
        while (index >= 0 && s[index] == ' ') --index;
        while (index >= 0 && s[index] != ' ') --index, ++count;
        return count;
    }
};
