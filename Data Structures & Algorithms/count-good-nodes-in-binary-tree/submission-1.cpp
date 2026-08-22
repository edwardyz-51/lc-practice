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
        int good = 0;
        countGoodNodes(root,-INFINITY,good);
        return good;
    }

    void countGoodNodes(TreeNode*root, int min, int&good){
        if (!root) return;
        if (root->val >= min) {
            good++;
            min = root->val;
        }

        countGoodNodes(root->left,min,good);
        countGoodNodes(root->right,min,good);
    }
};
