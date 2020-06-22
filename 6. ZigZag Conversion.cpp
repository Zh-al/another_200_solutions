class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result(s.length(), ' ');
        bool downSide = true;
        int posResult = 0;
        int downStep = 2 * numRows - 2;
        int upStep = 0;
        int step = downStep;
        
        // Complexity: O(n), just one move for each symbol
        
        for(int j = 0; j < numRows; ++j) {
            int i = j;
            downSide = true;
            while (i < s.length()) {
                step = downSide ? downStep : upStep;
                downSide = !downSide;
                if (step <= 0) {
                    continue;
                }
                result[posResult++] = s[i];
                i += step;
            }
            downStep -= 2;
            upStep += 2;
        }
        
        return result;
    }
};
