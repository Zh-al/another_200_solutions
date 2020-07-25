//https://leetcode.com/problems/relative-ranks/
//O(nlogn) - time comlpexity, O(n) - additional space

class Solution {
public:
 
    struct athlete {
        int score;
        int index;
 
        friend bool operator<(const athlete &left, const athlete &right) {
            return left.score < right.score;
        }
    };
 
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<athlete> athletes(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            athletes[i] = {nums[i], i};
        }
        sort(athletes.rbegin(), athletes.rend());
        vector<string> result(athletes.size());
        for (int i = 0; i < athletes.size(); ++i) {
            if (i > 2) {
                result[athletes[i].index] = to_string(i + 1);
            } else if (i == 0) {
                result[athletes[i].index] = "Gold Medal";
            } else if (i == 1) {
                result[athletes[i].index] = "Silver Medal";
            } else if (i == 2) {
                result[athletes[i].index] = "Bronze Medal";
            }
        }
        return result;
    }
};
