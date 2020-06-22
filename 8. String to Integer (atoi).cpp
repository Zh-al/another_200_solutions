class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0) {
            return 0;
        }
        pair<size_t, size_t> indexes = findFirstNumber(str);
        str = str.substr(indexes.first, indexes.second - indexes.first);
        cutZeros(str);
        if (!hasDigit(str)) {
            return 0;
        }
        size_t size = str.length();
        long long number = str[size - 1] - '0';
        int index = (int)size - 2;
        long long order = 10;
        while (index >= 0 && isDigit(str[index])) {
            number += (str[index] - '0') * order;
            if (number >= (long long)INT_MAX + 1 || order > INT_MAX) {
                // Overflow
                if (str[0] == '-') {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            }
            --index;
            order *= 10;
        }
        return str[0] == '-' ? -number : number;
    }
    
    void cutZeros(string &str) {
        size_t index = 0;
        if (str[index] == '+' || str[index] == '-') {
            ++index;
        }
        while (index < str.length() && str[index] == '0') {
            ++index;
        }
        if (str[0] == '+' || str[0] == '-') {
            str = str.substr(0, 1) + str.substr(index, str.length() - index);
        } else {
            str = str.substr(index, str.length() - index);
        }
    }

    bool hasDigit(const string &str) {
        for (size_t i = 0; i < str.length(); ++i) {
            if (isDigit(str[i])) {
                return true;
            }
        }
        return false;
    }

    bool isDigit(const char &c) {
        return (c >= '0' && c <= '9');
    }

    pair<size_t, size_t> findFirstNumber(const string &str) {
        bool firstWhiteSpaces = true;
        bool firstSign = true;
        bool firstNotWhiteSpaceChanged = false;
        size_t firstNotWhiteSpace = str.length() - 1;
        size_t index = 0;
        while (index < str.length()) {
            if (str[index] == ' ') {
                if (firstWhiteSpaces) {
                    ++index;
                    continue;
                } else {
                    return {firstNotWhiteSpace, index};
                }
            } else {
                firstWhiteSpaces = false;
            }
            if (!firstNotWhiteSpaceChanged) {
                firstNotWhiteSpaceChanged = true;
                firstNotWhiteSpace = index;
            }
            if (str[index] == '+' || str[index] == '-') {
                if (firstSign) {
                    firstSign = false;
                    ++index;
                    continue;
                } else {
                    return {firstNotWhiteSpace, index};
                }
            }
            firstSign = false;
            if (isDigit(str[index])) {
                ++index;
                continue;
            }
            // If go there => str[index] not valid character
            return {firstNotWhiteSpace, index};
        }
        return {firstNotWhiteSpace, index};
    }

    bool validCharacter(const char &c) {
        return (c == '+' || c == '-' || c == ' ' || (c >= '0' && c <= '9'));
    }
};
