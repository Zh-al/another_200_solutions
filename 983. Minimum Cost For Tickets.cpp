//https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
private:
    vector<int> days;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> minCosts(days.size() + 1);
        minCosts[0] = 0;
        this->days = days;
        for (int i = 0; i < days.size(); ++i) {
            minCosts[i + 1] = min(minCosts[i] + costs[0], minCosts[includedWeek(i) + 1] + costs[1]);
            minCosts[i + 1] = min(minCosts[i + 1], minCosts[includedMonth(i) + 1] + costs[2]);
        }
        return minCosts[minCosts.size() - 1];
    } 
    
    int includedWeek(int currentDayIndex) {
        int weekStartIndex = currentDayIndex;
        while (weekStartIndex >= 0 && days[currentDayIndex] - days[weekStartIndex] < 7) --weekStartIndex;
        return weekStartIndex;
    }
    
    int includedMonth(int currentDayIndex) {
        int monthStartIndex = currentDayIndex;
        while (monthStartIndex >= 0 && days[currentDayIndex] - days[monthStartIndex] < 30) --monthStartIndex;
        return monthStartIndex;
    }

};
