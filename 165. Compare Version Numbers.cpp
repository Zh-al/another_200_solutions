//https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        v1 = split(version1, '.');
        v2 = split(version2, '.');
        return compareVersion(v1, v2);
    }
    
    int compareVersion(const vector<string>& v1, const vector<string>& v2) {
        if (v1.size() < v2.size())
            return -compareVersion(v2, v1); // * (-1) because swap result
        int i = 0;
        while (i < v2.size()) {
            int num1 = stoi(v1[i]);
            int num2 = stoi(v2[i]);
            if (num1 < num2) 
                return -1;
            else if (num1 > num2) 
                return 1;
            else 
                ++i;
        }
        while (i < v1.size())
            if (stoi(v1[i]) != 0)
                return 1;
            else
                ++i;
        return 0;
    }
    
    vector<string> split (string s, char delim) {
        s += delim;
        vector<string> res;
        int start = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == delim) {
                res.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        return res;
    }
};
