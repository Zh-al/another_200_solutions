//https://leetcode.com/problems/subsets/

class Solution {
public:
    int binaryInclude;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetsQuantity = 1;
        subsetsQuantity <<= (int)nums.size();
        vector<vector<int>> result(subsetsQuantity);
        binaryInclude = 0;
        while (binaryInclude < subsetsQuantity) {
            result[binaryInclude] = createSubset(nums);
            nextSubset();
        }
        return result;
    }
    
    vector<int> createSubset(vector<int>& nums) {
        vector<int> subset;
        int index = (int)nums.size() - 1;
        int include = binaryInclude;
        while (include) {
            if (include & 1) subset.push_back(nums[index]);
            --index;
            include >>= 1;
        }
        return subset;
    }
    
    void nextSubset() {
       ++binaryInclude; 
    }
};
