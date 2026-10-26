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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target) ? root : nullptr;
    }
    bool dfs(TreeNode* node, int target){
        if (!node) return false;
        bool 
        right = dfs(node->right,target),
        left = dfs(node->left,target);
        if (!left && !right && node->val == target) return false;
        if (!right) node->right = nullptr;
        if (!left) node->left = nullptr;
        return true;
    }

};