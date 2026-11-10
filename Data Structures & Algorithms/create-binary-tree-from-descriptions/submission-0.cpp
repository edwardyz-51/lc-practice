class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<TreeNode*,int>indegrees;
        unordered_map<int,TreeNode*> nodes;
        for (const vector<int>& description : descriptions){
            int p = description[0], c = description[1];
            bool isLeft = description[2];
            TreeNode* parent = nodes.contains(p) ? nodes[p] : new TreeNode(p);
            nodes[p] = parent;
            TreeNode* child = nodes.contains(c) ? nodes[c] : new TreeNode(c);
            nodes[c] = child;
            if (isLeft) parent->left = child;
            else parent->right = child;
            indegrees[child]++;
            indegrees[parent] = indegrees[parent];
        }
        for (auto [node, degrees] : indegrees) if (!degrees) return node;
        return nullptr;
    }
};
