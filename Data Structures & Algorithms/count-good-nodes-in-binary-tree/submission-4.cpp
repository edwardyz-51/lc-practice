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
    void dfs(TreeNode* root, int max_node, int& ans){
        if (!root) return;
        if (root->val >= max_node){
            ans++;
            max_node=root->val;
        } 
        dfs(root->left,max_node,ans);
        dfs(root->right,max_node,ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root,INT_MIN,ans);
        return ans;
    }
};
