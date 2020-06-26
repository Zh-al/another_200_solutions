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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> result;
        dfs(root, {}, 0, sum, result);
        return result;
    }
    
    void dfs(TreeNode* root, vector<int> currentPath, int sum, int target, vector<vector<int>> &result) {
        if (root == NULL) {
            return;
        }
        currentPath.push_back(root->val);
        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                result.push_back(currentPath);
            }
            return;
        }
        
        dfs(root->left, currentPath, sum, target, result);
        dfs(root->right, currentPath, sum, target, result);
    }
};
