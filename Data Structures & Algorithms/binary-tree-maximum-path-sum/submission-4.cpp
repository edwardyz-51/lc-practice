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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }   

    int maxPath(TreeNode* root){
        if (!root) return 0;
        int left = max(0,maxPath(root->left));
        int right = max(0,maxPath(root->right));
        int path =  left+right + root->val;
        maxSum = path>maxSum ? path : maxSum;
        return root->val + max(left,right);
    }
};
