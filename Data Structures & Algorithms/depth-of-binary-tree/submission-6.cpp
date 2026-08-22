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
    int maxDepth(TreeNode* root) {
        return depthf(root,0);
    }

    int depthf (TreeNode* n, int depth){
        if (!n) return depth;
        int l = depthf(n->left,depth+1);
        int r = depthf(n->right,depth+1);
        return max(l,r);
    }
};
