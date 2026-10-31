/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        auto postorder = [&ans](this auto& self, Node*cur)->void{
            if (!cur)return;
            for (Node*child : cur->children) self(child);
            ans.push_back(cur->val);
        };
        postorder(root);
        return ans;
    }
};