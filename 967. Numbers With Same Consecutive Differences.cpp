//https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
private:
    int diff;
    vector<int> result;
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N < 1) return {1, 2, 3, 4, 5, 6, 7, 8, 9}; // leetcode needs it...
        if (K < 0 || K > 9) return {};
        // if (N > 9) N = 9;
        diff = K;
        vector<int> number(N);
        result.clear();
        for (int digit = 0; digit <= 9; ++digit) {
            number[N - 1] = digit;
            generateNumber(number, N - 2);
        }
        return result;
    }
    
    // we can get number with link, because we generate number sequentially, one by one, then rewrite needed cells
    void generateNumber(vector<int>& number, int index) {
        if (index < 0) {
            if (number[0] != 0 || number.size() == 1)
                result.push_back(constructNumber(number));
            return;
        }
        if (isDigit(number[index + 1] + diff)) {
            number[index] = number[index + 1] + diff;
            generateNumber(number, index - 1);
        }
        if (diff != 0 && isDigit(number[index + 1] - diff)) {
            number[index] = number[index + 1] - diff;
            generateNumber(number, index - 1);
        }
    }
    
    int constructNumber(const vector<int>& number) {
        int num = 0;
        int order = 1;
        for (int i = (int)number.size() - 1; i >= 0; --i) {
            if (i != (int)number.size() - 1) order *= 10;
            num += number[i] * order;
        }
        return num;
    }
    
    bool isDigit(int num) {
        return (num >= 0 && num <= 9);
    }
};
