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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
    
    void dfs(TreeNode* root, int depth, vector<vector<int>> &result) {
        if (root == NULL)
            return;
        if (result.size() <= depth) {
            result.push_back(vector<int>(1, root->val));
        } else {
            result[depth].push_back(root->val);
        }
        dfs(root->left, depth + 1, result);
        dfs(root->right, depth + 1, result);
    }
    
    
};
