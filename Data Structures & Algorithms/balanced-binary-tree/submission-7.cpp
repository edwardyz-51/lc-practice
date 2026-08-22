class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

private:
    // returns {isBalanced, height}
    pair<bool, int> dfs(TreeNode* node) {
        if (!node) return {true, 0};

        auto [lbalanced, lheight] = dfs(node->left);
        if (!lbalanced) return {false, 0}; // early exit

        auto [rbalanced, rheight] = dfs(node->right);
        if (!rbalanced) return {false, 0}; // early exit

        bool diff = (abs(lheight - rheight) <= 1);
        int h = 1 + max(lheight, rheight);

        return {diff, h};
    }
};
