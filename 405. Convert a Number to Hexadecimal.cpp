class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        bool negative = false;
        if (num < 0) {
            negative = true;
            num += 1;
            num = -num;
        }
        vector<int> hex(8, 0);
        int index = 7;
        while (num > 0) {
            hex[index--] = num % 16;
            num /= 16;
        }
        if (negative) {
            for (int &i : hex) {
                i = 15 - i;
            }
        }
        string result;
        bool skip = true;
        for (int i : hex) {
            if (skip && i == 0) {
                continue;
            } else {
                skip = false;
                result.push_back(TO_HEX.at(i));
            }
        }
        return result;
    }
    
    const map<int, char> TO_HEX = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, 
                             {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
                             {8, '8'}, {9, '9'}, {10, 'a'}, {11, 'b'},
                             {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}};
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().toHex(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
