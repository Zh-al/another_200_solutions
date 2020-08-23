//https://leetcode.com/problems/find-common-characters/

class Solution {
private:
    vector<int> countLetters;
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.size() == 0) return {};
        countLetters.clear();
        countLetters.resize('z' - 'a' + 1, INT_MAX);
        for (const string &word : A) {
            vector<int> count('z' - 'a' + 1, 0);
            for (char letter : word) ++count[letter - 'a'];
            for (int i = 0; i < count.size(); ++i)
                if (count[i] < countLetters[i]) countLetters[i] = count[i];
        }
        vector<string> result;
        for (int i = 0; i < countLetters.size(); ++i) {
            for (int j = 0; j < countLetters[i]; ++j) {
                result.push_back(string(1, 'a' + i));
            }
        }
        return result;
    }
};
