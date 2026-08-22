/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

    unordered_map<Node*,Node*>map; 
    //stores copies, ex if A and B both point to C, when A calls copy(C) store C so B doesnt do the same. 
    //Also prevents infinite loops

public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (map.count(head)) return map[head];
        Node* copy = new Node(head->val);

        map[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);
        return copy;
    }
};
