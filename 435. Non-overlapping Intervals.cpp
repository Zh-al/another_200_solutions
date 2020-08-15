//https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
private:
    static bool comp(const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[0] < rhs[0];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int count = 0;
        int past = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[past][1] > intervals[i][0]) {
                ++count;
                if (intervals[past][1] > intervals[i][1]) 
                    past = i;
                // else past = past
            } else past = i;
        }
        return count;
    }
};
