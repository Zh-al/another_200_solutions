//https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution {
public:
    vector<int> shortestToChar(string &s, char c) {
        vector<int> distances(s.size());
        int pastCharIndex; 
        int nextCharIndex = -(int)s.size();
        int pos = 0;
        while (pos < s.size() && pastCharIndex != (int)s.size() * 2) {
            pastCharIndex = nextCharIndex;
            nextCharIndex = findNextCharIndex(s, c, pos);
            while (pos < s.size() && pos <= nextCharIndex) {
                distances[pos] = min(pos - pastCharIndex, nextCharIndex - pos);
                ++pos;
            }
        }
        return distances;
    }
    
    int findNextCharIndex(string &s, char c, int startIndex) {
        for (int i = startIndex; i < s.size(); ++i) {
            if (s[i] == c) return i;
        }
        return (int)s.size() * 2;
    }
};
