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
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPath(root, maxSum);
        return maxSum;
    }   

    int maxPath(TreeNode* root, int& ans){
        if (!root) return 0;
        int left = max(0,maxPath(root->left,ans));
        int right = max(0,maxPath(root->right,ans));
        int path =  left+right + root->val;
        ans = max(ans,path);
        return root->val + max(left,right);
    }
};
