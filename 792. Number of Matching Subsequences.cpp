class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<string, int> wordsCount;
        for (const string &word: words) {
            ++wordsCount[word];
        }
        int count = 0;
        for (const auto &word : wordsCount) {
            if (isSubsequence(S, word.first)) {
                count += word.second;
            }
        }   
        return count;
    }
    
    bool isSubsequence(const string &t, const string &s) {
        int indexS = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (indexS == s.size()) {
                return true;
            }
            if (s[indexS] == t[i]) {
                ++indexS;
            }
        }
        return indexS == s.size();
    }
};
