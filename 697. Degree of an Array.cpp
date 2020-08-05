//https://leetcode.com/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        for (int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
            if (count[nums[i]] == 1) {
                left[nums[i]] = i;
            }
            right[nums[i]] = i;
        }
        int frequency = 0;
        int length = 1;
        for (auto [num, val] : count) {
            if (val > frequency) {
                frequency = val;
                length = right[num] - left[num] + 1;
            } else if (val == frequency) {
                length = min(length, right[num] - left[num] + 1);
            }
        }
        return length;
    }
};
