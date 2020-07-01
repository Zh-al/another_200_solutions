class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0, right = 1;
        int sum = nums[0];
        while (right < nums.size() && sum < s) {
            sum += nums[right++];
        }
        if (sum < s) {
            return 0;
        }
        while (sum >= s) {
            sum -= nums[left++];
        }
        int minLen = right - left + 1;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= s) {
                sum -= nums[left++];
            }
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
            }
        }
        return minLen;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int s = stringToInteger(line);
        getline(cin, line);
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().minSubArrayLen(s, nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
