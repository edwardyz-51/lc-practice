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
    int rob(TreeNode* root) {
        auto HouseRobber = [&](this auto& self, TreeNode * cur)->pair<int,int>{
            if (!cur) return {0,0};
            pair<int,int> left = self(cur->left);
            pair<int,int> right = self(cur->right);

            int not_robbed = max(left.first,left.second)+max(right.first,right.second);
            int robbed = cur->val + left.first + right.first;
            return {not_robbed,robbed};
        };
        pair<int,int> tmp = HouseRobber(root);
        return max(tmp.first,tmp.second);
    }
};