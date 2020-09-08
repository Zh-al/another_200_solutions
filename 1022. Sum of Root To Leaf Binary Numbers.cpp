//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int result;
    
    int sumRootToLeaf(TreeNode* root) {
        result = 0;    
        string temp;
        DFS(root, temp);
        return result;
    }
    
    void DFS(TreeNode* root, string& binNumber) {
        if (root == NULL)
            return;
        binNumber += root->val + '0';
        if (root->left == NULL && root->right == NULL) {
            result += stoi(binNumber, 0, 2);
            return;
        }
        if (root->left != NULL) {
            DFS(root->left, binNumber);
            binNumber.pop_back(); // deleting element that was added in prev DFS
        }
        if (root->right != NULL) {
            DFS(root->right, binNumber);
            binNumber.pop_back(); // same thing
        }
    }
};
