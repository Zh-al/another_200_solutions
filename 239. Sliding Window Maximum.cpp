class StackWithMax {
private:
    struct element {
        int value;
        int curMax;
    };

    vector<element> stack;

public:

    void push(int value) {
        if (stack.size() == 0) {
            stack.push_back({value, value});
        } else {
            int curMax = std::max(max(), value);
            stack.push_back({value, curMax});
        }
    }

    int pop() {
        assert(stack.size());
        int value = top();
        stack.pop_back();
        return value;
    }

    int max() const {
        assert(stack.size());
        return TopEl().curMax;
    }

    bool isEmpty() {
        return stack.size() == 0;
    }

    int top() const {
        assert(stack.size());
        return TopEl().value;
    }

private:
    element TopEl() const {
        assert(stack.size());
        return stack[stack.size() - 1];
    }
};

class QueueWithMax {
public:
    StackWithMax inbox;
    StackWithMax outbox;

    void queue(int item) {
        inbox.push(item);
    }

    int dequeue() {
        if (outbox.isEmpty()) {
            while (!inbox.isEmpty()) {
                outbox.push(inbox.pop());
            }
        }
        return outbox.pop();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int w) {
        QueueWithMax queue;
        for (int i = 0; i < std::min<int>(A.size(), w) - 1; ++i) {
            queue.queue(A[i]);
        }
        vector<int> result;
        for (int i = w - 1; i < A.size(); ++i) {
            queue.queue(A[i]);
            int inMax = queue.inbox.isEmpty() ? INT_MIN : queue.inbox.max();
            int outMax = queue.outbox.isEmpty() ? INT_MIN : queue.outbox.max();
            result.push_back(std::max(inMax, outMax));
            queue.dequeue();
        }
        return result;
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().maxSlidingWindow(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
