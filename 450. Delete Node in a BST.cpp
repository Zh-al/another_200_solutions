//https://leetcode.com/problems/delete-node-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto [needed, parent] = findNode(root, NULL, key);
        if (needed == NULL)
            return root;
        if (parent == NULL) {
            parent = new TreeNode(0, root, nullptr);  
            deleteThis(needed, parent);
            return parent->left;
        }
        deleteThis(needed, parent);
        return root;
    }
    
    pair<TreeNode*,TreeNode*> findNode(TreeNode* root, TreeNode* parent, int key) {
        if (root == NULL) return {NULL, NULL};
        if (root->val == key) 
            return make_pair(root, parent);
        if (root->val > key)
            return findNode(root->left, root, key);
        else 
            return findNode(root->right, root, key);
    }
        
    void deleteThis(TreeNode* node, TreeNode* parent) {
        if (node->left == NULL) {
            if (parent->left == node) 
                parent->left = node->right;
            else 
                parent->right = node->right;
            // node = NULL;
            return;
        }
        if (node->right == NULL) {
            if (parent->left == node) 
                parent->left = node->left;
            else 
                parent->right = node->left;            
            // node = NULL;
            return;
        }
        parent = node;
        TreeNode* temp = node->right;
        while (temp->left != NULL) {
            parent = temp;
            temp = temp->left;
        }
        node->val = temp->val;
        if (parent->left == temp)
            parent->left = temp->right;
        else 
            parent->right = temp->right;
    }
    
};
