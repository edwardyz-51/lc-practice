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
    struct Compare{
        bool operator() (ListNode*rhs,ListNode*lhs){
            return rhs->val > lhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>queue;
        for (ListNode* n : lists){
            if (n)queue.push(n);
        }
        ListNode head(0);
        ListNode* dummy =& head;
        while (!queue.empty()){
            ListNode* node = queue.top();
            queue.pop();
            if (node->next) queue.push(node->next);
            dummy->next = node;
            dummy = dummy->next;
            
        }
        return head.next;
    }
};
