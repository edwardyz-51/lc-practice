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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return nullptr;
        }
        if (max(p->val, q->val) < root->val) { //p < root && q < root
            return lowestCommonAncestor(root->left, p, q);
        } else if (min(p->val, q->val) > root->val) { //p>root && q> root
            return lowestCommonAncestor(root->right, p, q);
        } else { // p<root && q> root or p>root && q<root
            return root;
        }
    }
};