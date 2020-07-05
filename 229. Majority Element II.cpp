class Solution {
public:

    vector<int> majorityElement(vector<int>& nums) {
        int countFirst = 0, countSecond = 0;
        int firstTarget = 0, secondTarget = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (firstTarget == nums[i]) {
                ++countFirst;
            } else if (secondTarget == nums[i]) {
                ++countSecond;
            } else if (countFirst == 0) {
                firstTarget = nums[i];
                countFirst = 1;
            } else if (countSecond == 0) {
                secondTarget = nums[i];
                countSecond = 1;
            } else {
                --countFirst;
                --countSecond;
            }
            // checkTarget(countFirst, firstTarget, nums[i]);
            // checkTarget(countSecond, secondTarget, nums[i]);
        }
        int checkFirst = 0, checkSecond = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == firstTarget) {
                ++checkFirst;
            }
            if (nums[i] == secondTarget) {
                ++checkSecond;
            }
        }
        vector<int> result;
        if (checkFirst > nums.size() / 3) {
            result.push_back(firstTarget);
        }
        if (checkSecond > nums.size() / 3 && firstTarget != secondTarget) {
            result.push_back(secondTarget);
        }
        return result;
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
        vector<int> nums = stringToIntegerVector(line);
        
        vector<int> ret = Solution().majorityElement(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
