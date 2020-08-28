//https://leetcode.com/problems/implement-rand10-using-rand7/description/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// .|1 2 3 4 5 6 7
// -+-------------
// 1|8 9 0 1 2 3 4
// 2|5 6 7 8 9 0 1
// 3|2 3 4 5 6 7 8 
// 4|9 0 1 2 3 4 5
// 5|6 7 8 9 0 1 2
// 6|3 4 5 6 7 8 9
// 7|0 1 2 3 4 5 6
class Solution {

public:
    int rand10() {
        int res = 7 * rand7() + rand7();
        if (res < 10 || res >= 50)
            return rand10();
        return res % 10 + 1;
    }
};
