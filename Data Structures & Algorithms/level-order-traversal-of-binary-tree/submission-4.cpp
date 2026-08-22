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
vector<vector<int>>ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* cur, int depth){
        if(!cur) return;
        if (depth == ans.size()) ans.push_back({});
        ans[depth].push_back(cur->val);
        dfs(cur->left,depth+1);
        dfs(cur->right,depth+1);
    }
};
