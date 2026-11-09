class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;

        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (!node || k == 0) return;

            dfs(node->left);

            if (k == 0) return;
            if (--k == 0) {
                ans = node->val;
                return;
            }

            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};