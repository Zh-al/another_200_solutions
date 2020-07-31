//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int first = -1, last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != sorted[i]) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return first == -1 ? 0 : last - first + 1;
    }
};
