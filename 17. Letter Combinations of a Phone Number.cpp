class Solution {
public:
    vector<string> letterCombinations(string digits) { 
        int length = (int)digits.size();
        if (length == 0) {
            return {};
        }
        vector<string> result;
        vector<int> sequence(length, 0);
        vector<int> sizes(length);
        for (int i = 0; i < length; ++i) {
            sizes[i] = letters[digits[i]].size();
        }
        while (sequence[0] < sizes[0]) {
            string temp = "";
            for (int i = 0; i < length; ++i) {
                temp += letters[digits[i]][sequence[i]];
            }
            result.push_back(temp);
            nextSequence(sequence, sizes);
        }
        return result;
    }
    
    map<char, vector<char>> letters = {{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
                                       {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
                                       {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
                                       {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
    
    void nextSequence(vector<int> &sequence, const vector<int> &sizes) {
        int index = sequence.size() - 1;
        ++sequence[index];
        bool changed = true;
        while (index >= 1 && changed) {
            if (sequence[index] == sizes[index]) {
                sequence[index] = 0;
                ++sequence[--index];
                changed = true;
            } else {
                changed = false;
            }
        }
        
    }
    
};
