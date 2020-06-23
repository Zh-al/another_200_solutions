class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        int left = 0, right = v.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == v[mid]) {
                return mid;
            }
            if (target < v[mid]) {
                right = mid - 1;
            } else { // (target > v[mid])
                left = mid + 1;
            }
        }
        return left;
    }
};
