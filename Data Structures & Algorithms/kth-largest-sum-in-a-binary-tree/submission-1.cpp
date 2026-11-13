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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long >,greater<>>minq;
        queue<TreeNode*>bfs;
        bfs.push(root);

        while (!bfs.empty()){
            long long sum = 0, sz = bfs.size();
            for (int i = 0; i < sz; ++i){
                TreeNode* node = bfs.front();
                bfs.pop();
                sum+=node->val;
                if (node->left) bfs.push(node->left);
                if(node->right)bfs.push(node->right);
            }
            minq.push(sum);
            if (minq.size() > k) minq.pop();
        }
        return minq.size()==k?minq.top():-1;
    }
};
