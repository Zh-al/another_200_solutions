class Solution {
public:
    
    const char symbolsIncrease[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
    string intToRoman(int num) {
        string number = to_string(num);
        string result = "";
        int size = (int)number.length();
        for (int i = size - 1; i >= 0; --i) {
            if (number[i] >= '0' && number[i] <= '3') {
                for (int j = 0; j < number[i] - '0'; ++j) {
                    result.push_back(symbolsIncrease[2 * (size - i - 1)]);
                }
            } else if (number[i] == '4') {
                result.push_back(symbolsIncrease[2 * (size - i - 1) + 1]);
                result.push_back(symbolsIncrease[2 * (size - i - 1)]);
            } else if (number[i] >= '5' && number[i] <= '8') {
                for (int j = 0; j < number[i] - '0' - 5; ++j) {
                    result.push_back(symbolsIncrease[2 * (size - i - 1)]);
                }
                result.push_back(symbolsIncrease[2 * (size - i - 1) + 1]);
            } else { // number[i] == '9'
                result.push_back(symbolsIncrease[2 * (size - i - 1) + 2]);
                result.push_back(symbolsIncrease[2 * (size - i - 1)]);
            }
            
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
