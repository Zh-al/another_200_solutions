class Solution {
public:
    int minDistance(string word1, string word2) {
        // dynamic programming
        // mismatch, insertion, delete penalty = 1
        // match penalty = 0
        // Complexity and memory usage = O(n * m), where n and m size of word1 and word2
        vector<vector<int>> distance(word2.size() + 1, vector<int>(word1.size() + 1));
        for (int i = 0; i < word2.size() + 1; ++i) {
            distance[i][0] = i;
        }
        for (int i = 0; i < word1.size() + 1; ++i) {
            distance[0][i] = i;
        }
        for (int i = 1; i < word2.size() + 1; ++i) {
            for (int j = 1; j < word1.size() + 1; ++j) {
                distance[i][j] = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1);
                if (word2[i - 1] == word1[j - 1]) {
                    distance[i][j] = min(distance[i][j], distance[i - 1][j - 1]);
                } else { // word2[i - 1] != word1[j - 1]
                    distance[i][j] = min(distance[i][j], distance[i - 1][j - 1] + 1);
                }
            }
        }
        return distance[word2.size()][word1.size()];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);
        
        int ret = Solution().minDistance(word1, word2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
