class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int curIndex = 0;
        chars.push_back(0);
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == chars[i - 1]) {
                ++count;
            } else {
                chars[curIndex++] = chars[i - 1];
                if (count > 1) {
                    string countS = to_string(count);
                    for (int j = 0; j < countS.length(); ++j) {
                        chars[curIndex++] = countS[j];
                    }
                }
                count = 1;
            }
        }
        return curIndex;
    }
};
