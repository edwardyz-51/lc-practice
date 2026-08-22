class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, k, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, int& k, int& ans) {
        if (!node) return;

        dfs(node->left, k, ans);
        if (k == 0) return;          // already found, stop

        k--;
        if (k == 0) {                // this is the kth visited
            ans = node->val;
            return;
        }

        dfs(node->right, k, ans);
    }
};