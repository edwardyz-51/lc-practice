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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode dummy;
        ListNode* pointer = &dummy;
        ListNode*prevG = nullptr;
        while (head){
            if (size==0){
                if (prevG) {
                    pointer->next = reverseList(prevG);
                    pointer = prevG;
                }
                prevG = head;
            }
            size++;
            if (size % k == 0){
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                size = 0;
            } else head = head->next;
        }
        if (size!=0){
            pointer->next = prevG;
        } else {
            pointer->next = reverseList(prevG);
            pointer = prevG;
        }
        return dummy.next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};
