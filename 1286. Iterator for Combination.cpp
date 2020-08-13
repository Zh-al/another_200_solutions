//https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
private:
    vector<bool> includeChar;
    string chars;
    bool has_next;
public:
    CombinationIterator(string characters, int combinationLength) : chars(characters) {
        includeChar.resize(characters.size(), false);
        for (int i = 0; i < combinationLength; ++i) {
            includeChar[i] = true;
        }
        has_next = (combinationLength <= characters.size());
    }
    
    string next() {
        string result;
        for (int i = 0; i < chars.size(); ++i) {
            if (includeChar[i]) result.push_back(chars[i]);
        }
        int index = (int)includeChar.size() - 1;
        int countEndIncludes = 0;
        while (index >= 0 && includeChar[index]) index--, ++countEndIncludes; // skip all end includes
        while (index >= 0 && !includeChar[index]) index--; // skip gap between end include and another include
        if (index < 0) { // it was last combination
            has_next = false;
            return result;
        }
        swap(includeChar[index], includeChar[index + 1]); // move last non end include forward
        ++index;
        for (int i = 1; i <= countEndIncludes; ++i) { // refresh end includes
            swap(includeChar[index + i], includeChar[(int)includeChar.size() - i]);
        }
        return result;
    }
    
    bool hasNext() {
        return has_next;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
