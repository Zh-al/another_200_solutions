//https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int max_length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
            if (count.find(nums[i] + 1) != count.end())
                max_length = max(max_length, count[nums[i]] + count[nums[i] + 1]);
            if (count.find(nums[i] - 1) != count.end())
                max_length = max(max_length, count[nums[i]] + count[nums[i] - 1]);
        }
        return max_length;
    }
};
