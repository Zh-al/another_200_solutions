class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool added = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (added) {
                result.push_back(intervals[i]);
                continue;
            }
            if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) {
                newInterval[0] = intervals[i][0];
            } else if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
            } else { // newInterval[0] < intervals[i][0]
                if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                    newInterval[1] = intervals[i][1];
                } else if (newInterval[1] < intervals[i][0]) {
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                    added = true;
                } else { // newInterval[1] > intervals[i][1]
                    // do nothing newInterval overlap all intervals[i]
                }
            }
            if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                newInterval[1] = intervals[i][1];
            }
        }
        if (!added) {
            result.push_back(newInterval);
        }
        return result;
    }
};
