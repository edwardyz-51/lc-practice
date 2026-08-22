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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root,root->val-1,ans);
        return ans;
    }

    void dfs (TreeNode* node, int maximum, int&ans){
        if (!node) return;
        if (node->val >= maximum) ans++;
        dfs(node->right,max(maximum,node->val),ans);
        dfs(node->left,max(maximum,node->val),ans);
    }

};
