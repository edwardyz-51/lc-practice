class Solution {
    using pair = pair<int,int>;
public:
    // returns {notRobbed, robbed}
    pair dfs(TreeNode* node) {
        if (!node) 
            return {0, 0};

        pair left = dfs(node->left);
        pair right = dfs(node->right);

        // If we don't rob this node, take the best option for each child
        int notRobbed =
            max(left.first, left.second) +
            max(right.first, right.second);

        // If we rob this node, we cannot rob either child
        int robbed =
            node->val +
            left.first +
            right.first;

        return {notRobbed, robbed};
    }

    int rob(TreeNode* root) {
        pair result = dfs(root);
        return max(result.first, result.second);
    }
};