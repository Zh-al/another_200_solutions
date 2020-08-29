//https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        result.reserve(A.size() * 2); // the worst case
        int rightBorder = (int)A.size();
        while (!isSorted(A)) {
            int indexMax = findIndexMax(A, 0, rightBorder);
            result.push_back(indexMax + 1);
            result.push_back(rightBorder);
            reverse(A.begin(), A.begin() + indexMax + 1);
            reverse(A.begin(), A.begin() + rightBorder);
            --rightBorder;
        }
        return result;
    }
    
    // right border is not included
    int findIndexMax(const vector<int>& A, int leftBorder, int rightBorder) {
        int maxEl = A[leftBorder], indexMax = leftBorder;
        for (int i = leftBorder + 1; i < rightBorder; ++i) {
            if (A[i] > maxEl) maxEl = A[i], indexMax = i;
        }
        return indexMax;
    }
    
    bool isSorted(const vector<int>& A) {
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] < A[i - 1]) return false;
        }
        return true;
    }
};
