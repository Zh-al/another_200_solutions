//https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while (true) {
            result.push_back(nums);
            int i = (int)nums.size() - 2;
            while (i >= 0 && nums[i] > nums[i + 1]) --i;
            if (i == -1) 
                return result;
            int j = (int)nums.size() - 1;
            while (nums[j] < nums[i]) --j;
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
