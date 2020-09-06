//https://leetcode.com/problems/image-overlap/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int largest = 0;
        for (int xShift = 0; xShift < A.size(); ++xShift) 
            for (int yShift = 0; yShift < A[0].size(); ++yShift) {
                largest = max(largest, shiftAndCountOverlap(xShift, yShift, A, B));
                largest = max(largest, shiftAndCountOverlap(xShift, yShift, B, A));
            }
        return largest;
    }
    
    int shiftAndCountOverlap(int xShift, int yShift, 
                             const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int count = 0;
        for (int i = xShift; i < A.size(); ++i) {
            for (int j = yShift; j < B.size(); ++j) {
                if (A[i][j] && B[i - xShift][j - yShift])
                    ++count;
            }
        }
        return count;
    }
};
