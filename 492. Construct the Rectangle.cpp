//https://leetcode.com/problems/construct-the-rectangle/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        if (area == 0) {
            return {};
        }
        int L = (int)sqrt(area);
        int W = L;
        while (L * W != area) {
            if (L * W > area) {
                --W;
            } else {
                ++L;
            }
        }
        return {L, W};
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
        int area = stringToInteger(line);
        
        vector<int> ret = Solution().constructRectangle(area);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
