class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> result;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
            } else {
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back({left, right});
        return result;
    }
             
    static bool comparator(const vector<int> &left, const vector<int> &right) {
        if (left[0] == right[0]) {
            return right[1] < left[1];
        }
        return left[0] < right[0];
    }
};
