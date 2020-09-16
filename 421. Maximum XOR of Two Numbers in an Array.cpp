//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode() { next[0] = NULL; next[1] = NULL; }
    };
    
    int helper(TreeNode* node1, TreeNode* node2, long long bit) {
        if (node1->next[0] == NULL && node1->next[1] == NULL)
            return 0;
        int val = 0;
        bool bigger = false;
        if (node1->next[0] != NULL && node2->next[1] != NULL)
        {
            val = bit + helper(node1->next[0], node2->next[1], bit / 2);
            bigger = true;
        }
        if (node1->next[1] != NULL && node2->next[0] != NULL)
        {
            val = max<long long>(val, bit + helper(node1->next[1], node2->next[0], bit / 2));
            bigger = true;
        }
        if (!bigger) {
            if (node1->next[0] != NULL && node2->next[0] != NULL)
                val = helper(node1->next[0], node2->next[0], bit / 2);
            if (node1->next[1] != NULL && node2->next[1] != NULL)
                val = max(val, helper(node1->next[1], node2->next[1], bit / 2));
        }
        return val;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        for (int num : nums) {
            unsigned int mask = 0x80000000;
            TreeNode* node = root;
            for (int i = 0; i < 32; ++i) {
                int bit = (num & mask) == mask ? 1 : 0;
                if (node->next[bit] == NULL) {
                   node->next[bit] = new TreeNode();
                }
                node = node->next[bit];
                mask >>= 1;
            }
        }
        return helper(root, root, pow(2, 30) * 2);
    }
};
