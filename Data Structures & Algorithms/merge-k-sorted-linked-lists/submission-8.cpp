/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
struct Compare {
        bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>queue;
        for (auto l : lists) if(l) queue.push(l);
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (!queue.empty()){
            ListNode* n = queue.top();
            queue.pop();
            if (n->next) queue.push(n->next);
            cur->next = n;
            cur = cur->next;
        }
        return dummy.next;
    }
};
