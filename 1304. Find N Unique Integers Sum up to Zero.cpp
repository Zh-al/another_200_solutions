class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int l, r;
        if (n % 2) {
            result[n / 2];
            l = n / 2 - 1;
            r = n / 2 + 1;
        } else {
            l = n / 2 - 1;
            r = n / 2;

        } 
        int cnt = 1;
        while (l >= 0) {
           result[l--] = -cnt;
           result[r++] = cnt++;
        
        
        }
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().sumZero(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
