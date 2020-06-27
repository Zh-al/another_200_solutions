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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, 0, countLength(head) - 1);
    }

    ListNode* mergeSort(ListNode* head, int left, int right) {
        if (left > right) {
            return NULL;
        }
        if (left == right) {
            return head;
        }
        int mid = (left + right) / 2;
        ListNode* midHead = head;
        ListNode* prev = NULL;
        for (int i = left; i <= mid; ++i) {
            prev = midHead;
            midHead = midHead->next;
        }
        prev->next = NULL;
        ListNode* leftHead = mergeSort(head, left, mid);
        ListNode* rightHead = mergeSort(midHead, mid + 1,  right);
        return merge(leftHead, rightHead);
    }

    int countLength(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            ++count;
        }
        return count;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head;
        if (left->val < right->val) {
            head = left;
            left = left->next;
        } else {
            head = right;
            right = right->next;
        }
        ListNode* current = head;
        while (left != NULL || right != NULL) {
            int leftVal = INT_MAX, rightVal = INT_MAX;
            if (left != NULL) {
                leftVal = left->val;
            }
            if (right != NULL) {
                rightVal = right->val;
            }
            if (leftVal < rightVal) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        current->next = NULL;
        return head;
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
        
        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
