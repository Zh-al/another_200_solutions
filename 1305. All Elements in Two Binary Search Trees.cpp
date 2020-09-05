//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1 = getAllElements(root1), tree2 = getAllElements(root2);
        vector<int> result;
        std::merge(tree1.begin(), tree1.end(), tree2.begin(), tree2.end(), back_inserter(result));
        return result;
    }
    
    vector<int> getAllElements(TreeNode* root) {
        vector<int> result;
        LNR(root, result);
        return result;
    }
    
    void LNR(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        LNR(root->left, result);
        result.push_back(root->val);
        LNR(root->right, result);
    }
    
};
