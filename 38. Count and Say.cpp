class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string past = countAndSay(n - 1);
        string current = "";
        int count = 1;
        past += '#'; // to avoid copy pasting last check
        for (int i = 1; i < past.length(); ++i) {
            if (past[i] == past[i - 1]) {
                count += 1;
            } else {
                current += count + '0';
                current += past[i - 1];
                count = 1;
            }
        }
        return current;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
