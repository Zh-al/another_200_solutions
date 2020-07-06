/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != null) {
            int rootVal = root->val;
            pVal = p->val;
            qVal = q->val;
            if (rootVal < pVal && rootVal < qVal) {
                root = root->right;
            }
            if (rootVal > qVal && rootVal > pVal) {
                root = root->left;
            } else {    
                return root;                
            }
        }
        return null;
    }
};
