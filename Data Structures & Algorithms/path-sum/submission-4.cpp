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
    bool hasPathSum(TreeNode* root, int targetSum) {
        auto dfs = [&](this auto&self, TreeNode* node, int sum)->bool{
            if (!node) return false;
            sum+=node->val;
            return (!node->left&&!node->right)?sum==targetSum : 
                    self(node->left,sum) || self(node->right,sum);
        };
        return dfs(root,0);
        
    }
};