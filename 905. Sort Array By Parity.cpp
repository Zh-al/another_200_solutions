//https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result(A.size());
        int evenIndex = 0, oddIndex = (int)A.size() - 1;
        for (int number : A) {
            if (number % 2) result[oddIndex--] = number;
            else result[evenIndex++] = number;
        }
        return result;
    }
};
