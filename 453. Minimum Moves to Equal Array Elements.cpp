//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int min = getMin(nums);
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] - min;
        }
        return count;
    }
    
    int getMin(const vector<int> &nums) {
        int min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min) min = nums[i];
        }
        return min;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().minMoves(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
