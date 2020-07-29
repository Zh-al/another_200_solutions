//https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameter = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 1;
        depth(root);
        return diameter - 1;
    }
    
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        diameter = max(diameter, left + right + 1);
        return max(left, right) + 1;
    }
};
