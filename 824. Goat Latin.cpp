//https://leetcode.com/problems/goat-latin/

class Solution {
public:
    string toGoatLatin(string S) {
        if (S.length() == 0) return "";
        vector<string> words = split(S, ' ');
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (isVowel(words[i][0])) {
                result.append(words[i]);
            } else {
                result.append(words[i].substr(1, words[i].size() - 1));
                result.push_back(words[i][0]);
            }
            result.append("ma");
            result.append(generateEnding(i));
            result.push_back(' ');
        }
        result.pop_back();
        return result;
    }
    
    vector<string> split(const string &s, char delim) {
      stringstream ss(s);
      string item;
      vector<string> elems;
      while (getline(ss, item, delim)) {
        elems.push_back(item);
      }
      return elems;
    }
    
    bool isVowel(char letter) {
        return letter == 'A' || letter == 'E' || letter == 'I'
             || letter == 'O' || letter == 'U' || letter == 'a'
             || letter == 'e' || letter == 'i'  || letter == 'o'
             || letter == 'u';
    }
    
    string generateEnding(int index) {
        return string(index + 1, 'a');
    }
};
