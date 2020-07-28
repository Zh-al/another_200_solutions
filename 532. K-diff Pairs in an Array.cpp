//https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.size() == 0) return 0;
        int count = 0;
        set<pair<int, int> > pairs;
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        while (right < nums.size()) {
            if (left == right) {
                ++right;
                continue;
            }
            int diff = nums[right] - nums[left];
            if (diff == k) {
                pairs.insert(make_pair(nums[left], nums[right]));
                ++left, ++right;
            } else if (diff > k) {
                ++left;
            } else { // diff < k
                ++right;
            }
        }
        return pairs.size();
    }
};
