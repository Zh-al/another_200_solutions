class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int left, right, sum, size = nums.size();
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                left = j + 1;
                right = size - 1;
                while (left < right) {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        skipLeft(left, right, nums);
                        skipRight(left, right, nums);
                    } else if (sum > target) {
                        skipRight(left, right, nums);
                    } else { // sum < target
                        skipLeft(left, right, nums);
                    }
                }
            }
        }
        return result;
    }
    
    void skipLeft (int &left, const int &right, const vector<int> &nums) {
        ++left;
        while (left < right && nums[left] == nums[left - 1]) {
            ++left;
        }
    }
    
    void skipRight (const int &left, int &right, const vector<int> &nums) {
        --right;
        while (left < right && nums[right] == nums[right + 1]) {
            --right;
        }
    }
};
