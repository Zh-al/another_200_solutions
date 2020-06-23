class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else { // nums[mid] < nums[right]. != cause left < right && no duplicates
                right = mid;
            }
        }
        return nums[left];
    }
};
