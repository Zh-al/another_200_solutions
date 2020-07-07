class Solution {
public:
    int nthUglyNumber(int n) {
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        vector<int> nums = {1};
        for (int i = 1; i < n; ++i) {
            int newNum = min(nums[index2] * 2, 
                             min(nums[index3] * 3, nums[index5] * 5));
            nums.push_back(newNum);
            if (nums[index2] * 2 == newNum) {
                ++index2;
            }
            if (nums[index3] * 3 == newNum) {
                ++index3;
            }
            if (nums[index5] * 5 == newNum) {
                ++index5;
            }
        }
        return nums[n - 1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().nthUglyNumber(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
