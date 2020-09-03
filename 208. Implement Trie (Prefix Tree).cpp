//https://leetcode.com/problems/implement-trie-prefix-tree/

struct MyTreeNode {
    static const char END_CHAR = '`';
    char val;
    vector<MyTreeNode*> childrens;
    MyTreeNode() : val(END_CHAR) {}
    MyTreeNode(char x) : val(x) {}
    MyTreeNode(char x, vector<MyTreeNode*> childrens) : val(x), childrens(childrens) {}
};

class Trie {
public:
    MyTreeNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new MyTreeNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        MyTreeNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = getIndexMatchChildren(temp, word[i]);
            if (index == -1) {
                temp->childrens.push_back(new MyTreeNode(word[i]));
                temp = temp->childrens[temp->childrens.size() - 1];
            } else {
                temp = temp->childrens[index];
            }
        }
        temp->childrens.push_back(new MyTreeNode());
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        MyTreeNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = getIndexMatchChildren(temp, word[i]);
            if (index == -1)
                return false;
            temp = temp->childrens[index];
        }
        return getIndexMatchChildren(temp, MyTreeNode::END_CHAR) != -1;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        MyTreeNode* temp = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = getIndexMatchChildren(temp, prefix[i]);
            if (index == -1)
                return false;
            temp = temp->childrens[index];
        }
        return true;
    }

    int getIndexMatchChildren(MyTreeNode* node, char letter) {
        for (int i = 0; i < node->childrens.size(); ++i) {
            if (node->childrens[i]->val == letter)
                return i;
        }
        return -1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
