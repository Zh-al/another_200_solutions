//https://leetcode.com/problems/sequential-digits/

class Solution {
public:
    vector<int> allSequentialDigits;
    
    Solution() {
        allSequentialDigits.reserve(100);
        for (int length = 2; length < 10; ++length) {
            string sequentialDigit;
            for (char i = '1'; i < '1' + length; ++i) {
                sequentialDigit += i;
            }
            allSequentialDigits.push_back(stoi(sequentialDigit));
            while (sequentialDigit[length - 1] != '9') {
                for (int i = 0; i < length; ++i) {
                    ++sequentialDigit[i];
                }
                allSequentialDigits.push_back(stoi(sequentialDigit));
            }
        }
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int digit : allSequentialDigits) {
            if (digit >= low && digit <= high)
                result.push_back(digit);
        }
        return result;
    }
};
