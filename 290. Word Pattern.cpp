//https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() == 0 || str.size() == 0) return false;
        unordered_map <char, set <string> > cts;
        unordered_map <string, set <char> > stc;
        int indexS = 0, indexP = 0;
        str.push_back(' ');
        for (int i = 0; i < str.size(); ++i) {
            if (indexP >= pattern.size()) {
                return false;
            }
            if (str[i] == ' ') {
                string sub = str.substr(indexS, i - indexS);
                indexS = i + 1;
                cts[pattern[indexP]].insert(sub);
                stc[sub].insert(pattern[indexP++]);
            }
        }
        if (indexP != pattern.size()) return false;
        for (auto [k, v] : cts) if (v.size() > 1) return false;
        for (auto [k, v] : stc) if (v.size() > 1) return false;
        return true;
    }
};
