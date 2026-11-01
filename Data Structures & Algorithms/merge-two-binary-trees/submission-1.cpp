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
    TreeNode* mergeTrees(TreeNode* node1, TreeNode* node2) {
        return (!node1&&!node2) ? nullptr : new TreeNode(
                (node1?node1->val:0)+(node2?node2->val:0),
                mergeTrees((node1?node1->left:nullptr),(node2?node2->left:nullptr)),
                mergeTrees((node1?node1->right:nullptr),(node2?node2->right:nullptr))
                );
    }
};