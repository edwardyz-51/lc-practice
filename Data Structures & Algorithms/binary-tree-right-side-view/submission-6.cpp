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
vector<int>ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* cur, int depth){
        if (!cur) return;
        if (ans.size()==depth) ans.push_back(cur->val);
        dfs(cur->right,depth+1);
        dfs(cur->left,depth+1);
    }
};
