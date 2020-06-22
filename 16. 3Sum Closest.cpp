class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right;
        int size = (int)nums.size();
        int sum, closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            left = i + 1;
            right = size - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                }
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                if (sum > target) {
                    --right;
                    while (right > left && nums[right] == nums[right + 1]) {
                        --right;
                    }
                } else { // sum < k
                    ++left;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                }
            }
        }
        return closestSum;
    }
};
