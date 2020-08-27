//https://leetcode.com/problems/find-right-interval/

class Solution {
public:
    struct Data {
        vector<int> interval;
        int index;
    };
    
    vector<Data> v;
    
    static bool comp(const Data &rhs, const Data& lhs) {
        return rhs.interval[0] < lhs.interval[0];
    }
    
    int findRightPointIndex(int left, int right, int target) {
        if (left == v.size())
            return -1;
        if (left == right)
            return right;
        int mid = (right + left) / 2;
        if (v[mid].interval[0] == target) 
            return mid;
        if (v[mid].interval[0] > target)
            return findRightPointIndex(left, mid, target);
        else // v[mid].interval[0] < target
            return findRightPointIndex(mid + 1, right, target);
    }
    
    int findLeftMostIndex(int currentIndex) {
        if (currentIndex == -1)
            return -1;
        int minIndex = v[currentIndex].index;
        int index = currentIndex - 1;
        while (index >= 0 && v[currentIndex].interval[0] == v[index].interval[0]) {
            minIndex = min(minIndex, v[index].index);
            --index;
        }
        index = currentIndex + 1;
        while (index < v.size() && v[currentIndex].interval[0] == v[index].interval[0]) {
            minIndex = min(minIndex, v[index].index);
            ++index;
        }
        return minIndex;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        v.resize(intervals.size());
        for (int i = 0; i < intervals.size(); ++i) {
            v[i] = {intervals[i], i};
        }
        sort(v.begin(), v.end(), comp);
        vector<int> result(intervals.size());
        for (int i = 0; i < v.size(); ++i) {            
            result[v[i].index] = findLeftMostIndex(findRightPointIndex(i, v.size(), v[i].interval[1]));
        }
        return result;
    }
};
