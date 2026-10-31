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
    string tree2str(TreeNode* root) {
        auto dfs = [&](auto& self,TreeNode* node)->string{
            if (!node)return "";
            if (!node->left && !node->right) return to_string(node->val);
            return to_string(node->val) + '(' + self(self,node->left) + ')' + 
            (node->right ? ('(' + self(self,node->right) + ')') : "");
        };
        return dfs(dfs,root);
    }
};
