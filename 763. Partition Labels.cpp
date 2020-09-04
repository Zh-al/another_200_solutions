//https://leetcode.com/problems/partition-labels/

class Solution {
public:
    unordered_map<char, int> lastMap;
    
    vector<int> partitionLabels(string S) {
        for (int i = 0; i < S.size(); ++i) {
            lastMap[S[i]] = i + 1;
        }
        vector<int> result;
        int last = 0;
        while (last != S.size()) {
            int first = last;
            last = lastMap[S[first]];
            for (int i = first + 1; i < last; ++i) {
                last = max(last, lastMap[S[i]]);
            }
            result.push_back(last - first);
        }
        return result;
    }
};
