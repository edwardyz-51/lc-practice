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
        if (k==1 || !head) return head;
        int size=0;
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* prevG = nullptr;
        while (head){
            if (size==0) prevG = head;
            size++;
            head = head->next;
            if (size!=0 && size % k == 0) { 
                ListNode* prev = nullptr;
                ListNode* cur = prevG;
                while (cur && cur!=head) {
                    ListNode* temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                }
                tail->next = prev;
                tail = prevG;
                size = 0;
            }
        }
        if (size!=0) tail->next = prevG;
        return dummy.next;
    }

};
