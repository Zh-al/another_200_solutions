/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* current;
        ListNode* reversePreHead;
        ListNode* preHead;
        if (m == 1) {
            reversePreHead = new ListNode(0, head);
            current = reversePreHead;
            preHead = reversePreHead;
        } else {
            preHead = new ListNode(0, head);
            current = head;
            for (int i = 1; i < m - 1; ++i) {
                current = current->next;
            }
            reversePreHead = current;
        }
        current = current->next;
        ListNode* prev = current;
        ListNode* reverseLast = current;
        current = current->next;
        for (int i = 0; i < (n - m); ++i) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        reversePreHead->next = prev;
        reverseLast->next = current;
        return preHead->next;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().reverseBetween(head, m, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
