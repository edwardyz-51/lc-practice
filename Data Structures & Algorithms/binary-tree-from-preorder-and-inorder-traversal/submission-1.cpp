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
    unordered_map<int,int>inorder_idx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i){
            inorder_idx[inorder[i]]=i;
        }
        int next_root_ptr = 0;
        auto build = [&](this auto&& build, int left, int right)->TreeNode*{
            if (left>right) return nullptr;
            int val = preorder[next_root_ptr++];
            int idx = inorder_idx[val];
            TreeNode * cur = new TreeNode(val);
            cur->left = build(left,idx-1);
            cur->right = build(idx+1,right);
            return cur;
        };
        return build(0,n-1);

    }
};
