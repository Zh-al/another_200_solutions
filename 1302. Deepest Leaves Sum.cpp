//https://leetcode.com/problems/deepest-leaves-sum/

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
private:
    int depth;
    int sum;
public:
    int deepestLeavesSum(TreeNode* root) {
        depth = 0, sum = 0;
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode* root, int curDepth) {
        if (root == NULL) return;
        if (curDepth > depth) {
            depth = curDepth;
            sum = root->val;
        } else if (curDepth == depth) 
            sum += root->val;
        dfs(root->left, curDepth + 1);
        dfs(root->right, curDepth + 1);
    }
};
