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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto add = [](this auto&& add, ListNode* l1, ListNode*l2,int carry)->ListNode*{
            if (!l1&&!l2&&carry==0) return nullptr;
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1+v2 + carry;
            int val = sum % 10;
            int carryOn = sum / 10;
            ListNode* nl1 = l1 ? l1->next : nullptr;
            ListNode* nl2 = l2 ? l2->next : nullptr;
            ListNode* n = new ListNode(val);
            n->next = add(nl1,nl2,carryOn);
            return n;
        };
        return add(l1,l2,0);
    }

};
