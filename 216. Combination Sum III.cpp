//https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        vector<vector<int>> result;
        backtrack(n, k, comb, 0, result);
        return result;
    }
    
    void backtrack(int remain,  int k, vector<int>& comb, int nextStart, vector<vector<int>> &result) {
        if (remain == 0 && comb.size() == k) {
            result.push_back(comb);
            return;
        }
        if (remain < 0 || comb.size() == k) {
            return;
        }
        for (int i = nextStart; i < 9; ++i) {
            comb.push_back(i + 1);
            backtrack(remain - i - 1, k, comb, i + 1, result);
            comb.pop_back();
        }
    }
};
