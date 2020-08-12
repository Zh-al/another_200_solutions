//https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (int i = 0; i < rowIndex; ++i) {
            int past = 1;
            for (int j = 1; j < i + 2; ++j) {
                row[j] += past;
                past = row[j] - past;
            }
        }
        return row;
    }
};
