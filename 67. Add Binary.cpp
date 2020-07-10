class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int indexA = (int)a.size() - 1;
        int indexB = (int)b.size() - 1;
        int overflow = 0;
        while (indexA >= 0 && indexB >= 0) {
            int digit = a[indexA--] + b[indexB--] - 2 * '0' + overflow;
            result.push_back(digit % 2 + '0');
            overflow = digit / 2;
        }
        while (indexA >= 0) {
            int digit = a[indexA--] - '0' + overflow;
            result.push_back(digit % 2 + '0');
            overflow = digit / 2;
        }
        while (indexB >= 0) {
            int digit = b[indexB--] - '0' + overflow;
            result.push_back(digit % 2 + '0');
            overflow = digit / 2;
        }
        if (overflow) {
            result.push_back(overflow + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
