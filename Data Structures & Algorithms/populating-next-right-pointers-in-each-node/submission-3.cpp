/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)return root;
        queue<Node*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            size_t sz=bfs.size();
            for (size_t i(0uz); i < sz; ++i){
                Node * cur = bfs.front();
                bfs.pop();
                cur->next = i+1 == sz ? nullptr : bfs.front();
                if (cur->left)bfs.push(cur->left);
                if (cur->right)bfs.push(cur->right);
            }
        }
        return root;
    }
};