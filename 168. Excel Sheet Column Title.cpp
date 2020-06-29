class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n != 0) {
            n -= 1;
            result += (n % 26 + 'A');
            n -= n % 26;
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().convertToTitle(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
