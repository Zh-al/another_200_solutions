//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int left = 0, right = (int)nums.size() - 1;
        while (left < (int)nums.size() - 1 && nums[left] <= nums[left + 1]) ++left;
        while (right >= 1 && nums[right] >= nums[right - 1]) --right;
        int _min = nums[left], _max = nums[left];
        for (int i = left + 1; i <= right; ++i) {
            _min = min(_min, nums[i]);
            _max = max(_max, nums[i]);
        }
        while (left >= 0 && _min < nums[left]) --left;
        while (right < nums.size() && _max > nums[right]) ++right;
        return right - left < 1 ? 0 : right - left - 1;
    }
};
