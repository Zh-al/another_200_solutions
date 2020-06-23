class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> center = binarySearch(nums, target, 0, nums.size() - 1);
        if (center[0] == -1) {
            return {-1, -1};
        }
        vector<int> left = center;
        vector<int> right = center;
        while (nums[left[1]] != target) {
            left = binarySearch(nums, target, left[1] + 1, left[0]);
        } 
        while (nums[right[2]] != target) {
            right = binarySearch(nums, target, right[0], right[2] - 1);
        }
        return {left[1], right[2]};
    }
    
    vector<int> binarySearch(const vector<int> &v, int target, int left, int right) {
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == v[mid]) {
                return {mid, left, right};
            }
            if (target < v[mid]) {
                right = mid - 1;
            } else { // (target > v[mid]) 
                left = mid + 1;
            }
        }
        return {-1, left, right};
    }
};
