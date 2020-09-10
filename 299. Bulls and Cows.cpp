//https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        map <char, int> sec, gue;
        int cntA = 0, cntB = 0;
        for (int i = 0; i < secret.length(); i++){
            if (secret[i] == guess[i])
                cntA++;
            sec[secret[i]]++;
            gue[guess[i]]++;
        }
        res += to_string(cntA) + 'A';
        for (auto i : sec){
            cntB += min (sec[i.first], gue[i.first]);
        }
        res += to_string (cntB - cntA) + 'B';
        return res;
    }
};
