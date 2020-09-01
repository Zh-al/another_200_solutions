//https://leetcode.com/problems/largest-time-for-given-digits/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int maxTime = -1;
        sort(A.begin(), A.end());
        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];
            if (hour < 24 && minute < 60)
                maxTime = max(maxTime, hour * 60 + minute);
        } while (next_permutation(A.begin(), A.end()));
        if (maxTime == -1)
            return "";
        ostringstream res;
        res << setw(2) << setfill('0') << maxTime / 60
           << ":" << setw(2) << setfill('0') << maxTime % 60;
        return res.str();
    }
};
