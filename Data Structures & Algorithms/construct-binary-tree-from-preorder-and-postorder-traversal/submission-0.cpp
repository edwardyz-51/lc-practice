
class Solution {
public:
    TreeNode* constructFromPrePost(
        vector<int>& preorder,
        vector<int>& postorder
    ) {
        int preIDX = 0;
        unordered_map<int, int> getPost;
        for (int i = 0; i < postorder.size(); ++i)
            getPost[postorder[i]] = i;
        auto build = [&](this auto& build,
                         int left, int right) -> TreeNode* {
            if (left > right)
                return nullptr;
            TreeNode* node = new TreeNode(preorder[preIDX++]);
            if (left == right)
                return node;

            // Next preorder element is the left subtree root.
            int postIDX = getPost[preorder[preIDX]];

            node->left = build(left, postIDX);
            node->right = build(postIDX + 1, right - 1);

            return node;
        };

        return build(0, postorder.size() - 1);
    }
};
