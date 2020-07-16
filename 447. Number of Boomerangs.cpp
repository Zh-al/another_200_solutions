class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> distCount;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) continue;
                ++distCount[sqrDistance(points[i], points[j])];
            }
            for (auto [dist, quantity] : distCount) {
                // quantity for j-th place, quantity - 1 for k-th place
                count += quantity * (quantity - 1);
            }
        }
        return count;
    }
    
    int sqrDistance(const vector<int> &a, const vector<int> &b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};
