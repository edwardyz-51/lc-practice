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
    bool isValidBST(TreeNode* root) {
        return validate(root,INT_MIN,INT_MAX);
    }

    bool validate(TreeNode* root, int left, int right){
        if (!root) return true;
        if (root->val <= left || root->val >= right) return false;
        return validate(root->left, left, root->val) && validate(root->right, root->val, right);
    }
};
