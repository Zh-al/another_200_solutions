class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> vectors;
        int size = (int)nums.size();
        int j, k, sum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; ++i){
            j = i + 1;
            k = size - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vectors.insert({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                } else if (sum > 0) {
                    --k;
                } else { // sum < 0
                    ++j;
                }
            }
        }
        vector<vector<int>> result(vectors.begin(), vectors.end());
        return result;
    }
};
