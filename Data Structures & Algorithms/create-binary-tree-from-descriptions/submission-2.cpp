class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<TreeNode*> isChild;
        unordered_map<int,TreeNode*> nodes;
        for (const vector<int>& description : descriptions){
            int p = description[0], c = description[1];
            bool isLeft = description[2];
            TreeNode* parent, * child;
            auto pit = nodes.find(p);
            if (pit == nodes.end()) parent = new TreeNode(p), nodes[p]=parent;
            else parent = pit->second;
            auto cit = nodes.find(c);
            if (cit == nodes.end()) child = new TreeNode(c), nodes[c]=child;
            else child = cit->second;

            if (isLeft) parent->left = child;
            else parent->right = child;

            isChild.insert(child);
        }
        for (auto [val, node] : nodes) if (!isChild.contains(node)) return node;
        return nullptr;
    }
};
