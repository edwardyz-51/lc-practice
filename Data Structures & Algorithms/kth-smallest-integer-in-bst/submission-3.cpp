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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>maxHeap;
        dfs(root,k,maxHeap);
        return maxHeap.top();
    }
    void dfs(TreeNode* root, int k, priority_queue<int>&maxHeap){
        if (!root) return;
        maxHeap.push(root->val);
        if (maxHeap.size()>k) maxHeap.pop();
        dfs(root->left,k,maxHeap);
        dfs(root->right,k,maxHeap);
    }
};
