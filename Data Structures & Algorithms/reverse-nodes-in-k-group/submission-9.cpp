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
                
                prevG = head;
            }
            size++;
            if (size % k == 0) {
                size = 0;
                head = head->next;
                if (prevG) {
                    ListNode* prev = nullptr;
                    ListNode* cur = prevG;
                    while (cur && cur!=head) {
                    ListNode* temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                }
                    pointer->next = prev;
                    pointer = prevG;
                }
            } else head = head->next;
        }
        if (size!=0) pointer->next = prevG;
        //else pointer->next = reverseList(prevG);
        return dummy.next;
    }

};
