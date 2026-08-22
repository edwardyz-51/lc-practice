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
using heap = priority_queue<int, vector<int>, greater<int>>;
    int kthSmallest(TreeNode* root, int k) {
        heap minHeap;
        dfs(root,minHeap,k);
        for (int i =1; i<k; i++){
            minHeap.pop();
        }
        return minHeap.top();
    }

    void dfs(TreeNode* root, heap& minHeap,int k){
        if (!root) return;
        minHeap.push(root->val);
        dfs(root->right, minHeap,k); dfs(root->left,minHeap,k);

    }
};
