class Solution {
public:
    unordered_map<int, int> index;  // value -> inorder index
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        // Current root from preorder
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        // Split inorder into left and right subtrees
        int mid = index[rootVal];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
