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
    int max=0;
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        dfs(root,1);
        return max;
        
    }

    void dfs(TreeNode* root,int count){
        if(!root) return;
        if(count>max) max=count;
        dfs(root->right, count+1);
        dfs(root->left, count+1);
    }
};
