//https://leetcode.com/problems/distribute-candies-to-people/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int count = 1;
        while (candies > 0) {
            result[(count - 1) % num_people] += min(count, candies);
            candies -= count;
            ++count;
        }
        return result;
    }
};
