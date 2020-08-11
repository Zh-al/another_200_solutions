//https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        if (pattern.size() <= 1) return words;
        vector<string> result;
        for (string word : words) {
            if (wordPattern(pattern, word)) result.push_back(word);
        }
        return result;
    }
    
    bool wordPattern(string p, string s) {
        if (p.size() != s.size()) return false;
        unordered_map <char, set <char> > pts;
        unordered_map <char, set <char> > stp;
        int indexS = 0, indexP = 0;
        for (int i = 0; i < s.size(); ++i) {
            pts[p[i]].insert(s[i]);
            stp[s[i]].insert(p[i]);
        }
        for (auto [k, v] : pts) if (v.size() > 1) return false;
        for (auto [k, v] : stp) if (v.size() > 1) return false;
        return true;
    }
};
