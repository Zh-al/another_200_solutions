//https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = s.lower_bound(static_cast<long long>(nums[i]) - t);
            if (it != s.end() && abs(static_cast<long long>(*it) - nums[i]) <= t)
                return true;
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};
