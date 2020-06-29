class Solution {
public:
    bool isHappy(long long n) {
        set<int> s;
        int setSize = 0;
        do {
            s.insert(n);
            if (setSize == s.size()) {
                return false;
            }
            setSize = s.size();
            long long temp = 0;
            while (n != 0) {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        } while (n != 1);
        return n == 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
