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
    bool hasCycle(ListNode* head) {
        ListNode * fastHead = head;
        while (true) {
            if (head->next == nullptr || fastHead->next == nullptr) return false;
            head = head->next;
            fastHead = fastHead->next;
            if (fastHead->next == nullptr) return false;
            fastHead = fastHead->next;
            if (head==fastHead) return true;
        }
    }
};
