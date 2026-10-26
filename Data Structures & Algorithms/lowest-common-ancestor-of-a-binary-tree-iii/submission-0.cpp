/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    unordered_set<Node*>i,j;
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(p){
            if (j.contains(p)) return p;
            i.insert(p);
        }
        if(q){
            if (i.contains(q))return q;
            j.insert(q);
        }
        return lowestCommonAncestor((p ? p->parent : nullptr), (q ? q->parent : nullptr));
    }
};