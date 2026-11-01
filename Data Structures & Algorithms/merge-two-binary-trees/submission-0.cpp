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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        auto merge = [](this auto& merge, TreeNode* node1, TreeNode* node2)->TreeNode*{
            if(!node1&&!node2)return nullptr;
            TreeNode* tmp = new TreeNode(0);
            tmp->val += node1 ? node1->val : 0;
            tmp->val +=node2?node2->val:0;
            tmp->left=merge((node1?node1->left:nullptr),(node2?node2->left:nullptr));
            tmp->right=merge((node1?node1->right:nullptr),(node2?node2->right:nullptr));
            return tmp;
        };
        return merge(root1,root2);
    }
};