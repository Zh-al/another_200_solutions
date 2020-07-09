class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> countOccurrences;
        for (int i = 0; i < arr.size(); ++i) {
            ++countOccurrences[arr[i]];
        }
        set<int> occurrences;
        for (auto item : countOccurrences) {
            occurrences.insert(item.second);
        }
        return occurrences.size() == countOccurrences.size();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        
        bool ret = Solution().uniqueOccurrences(arr);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
