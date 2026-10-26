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
            if (!l1&&!l2&&!carry) return nullptr;
            int sum = (l1 ? l1->val : 0)+(l2 ? l2->val : 0) + carry;
            int val = sum % 10, carryOn = sum / 10;
            return new ListNode(val,add((l1 ? l1->next : nullptr),(l2 ? l2->next : nullptr),carryOn));
        };
        return add(l1,l2,0);
    }
};
