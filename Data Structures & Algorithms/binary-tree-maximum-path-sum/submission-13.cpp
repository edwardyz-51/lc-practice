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
        int ans = INT_MIN;
        auto dfs = [&ans](this auto&& dfs, TreeNode* cur)->int{
            if (!cur)return 0;
            int left = max(0,dfs(cur->left)),right = max(0,dfs(cur->right));
            ans=max(left+right+cur->val,ans);
            return cur->val + max(left,right);
        };
        dfs(root);
        return ans;
    }
};
