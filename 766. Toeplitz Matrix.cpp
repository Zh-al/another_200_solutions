//https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int indentBound = max(matrix.size(), matrix[0].size());
        for (int indent = 0; indent < indentBound; ++indent) {
            for (int i = 1; 
                 i < matrix.size() && i + indent < matrix[i].size(); 
                 ++i) {
                if (matrix[i][i + indent] != matrix[i - 1][i + indent - 1])
                    return false;
            }
            for (int i = 1; 
                 i + indent < matrix.size() && i < matrix[i + indent].size();
                 ++i) {
                if (matrix[i + indent][i] != matrix[i + indent - 1][i - 1])
                    return false;
            }
        }
        return true;
    }
};
