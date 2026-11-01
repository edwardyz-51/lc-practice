class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto build = [&](this auto& self, int left, int right) -> TreeNode* {
            if (left > right) return nullptr;
            int mid = left + (right - left) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = self(left, mid - 1);
            node->right = self(mid + 1, right);
            return node;
        };

        return build(0, static_cast<int>(nums.size()) - 1);
    }
};