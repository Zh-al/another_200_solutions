//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int result = INT_MIN;
        int maxProd = 1, minProd = 1;
        for (int num : nums) {
            if (num < 0)
                swap(maxProd, minProd);
            maxProd = max(maxProd * num, num);
            minProd = min(minProd * num, num);
            result = max(result, maxProd);
        }
        return result;
    }
};
