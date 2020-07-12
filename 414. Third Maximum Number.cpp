class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int firstMin = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < firstMin) 
                firstMin = nums[i];
        }
        int max1 = firstMin;
        int max2 = firstMin;
        int max3 = firstMin;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            
            }
            else if (nums[i] > max2 && nums[i] != max1) {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3 && nums[i] != max2 && nums[i] != max1) {
                max3 = nums[i];
            }
        }
        if (max3 == max2)
            return max1;
        return max3;
    }
};
