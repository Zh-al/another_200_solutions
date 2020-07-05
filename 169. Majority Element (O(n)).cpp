class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                target = nums[i];
            }
            if (target == nums[i]) {
                ++count;
            } else {
                --count;
            }
        }
        // int countCheck = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     if (target == nums[i]) {
        //         ++countCheck;
        //     }
        // }
        // if (countCheck > nums.size() / 2) {
        //     return target;
        // }
        return target;
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
        
        int ret = Solution().majorityElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
