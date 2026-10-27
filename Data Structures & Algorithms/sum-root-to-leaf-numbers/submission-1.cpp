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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<pair<int,TreeNode*>>bfs;
        bfs.emplace(0,root);
        while(!bfs.empty()){
            auto [val,cur]= bfs.front();
            bfs.pop();
            val = val * 10 + cur->val;
            if (!cur->left && !cur->right)
                ans+=val;
            
            if (cur->left) bfs.emplace(val,cur->left);
            if (cur->right) bfs.emplace(val,cur->right);
        }
        return ans;
        
    }
};