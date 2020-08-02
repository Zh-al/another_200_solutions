//https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;
        for (vector<int> coordinates : ops) {
            x = min(x, coordinates[0]);
            y = min(y, coordinates[1]);
        }
        return x * y;
    }
};
