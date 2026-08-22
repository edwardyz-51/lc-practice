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
        vector<ListNode*> groups;
        int size=0;
        while (head){
            if (size==0)groups.push_back(head);
            size++;
            if (size % k == 0){
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                size = 0;
                continue;
            } else head = head->next;
        }
        ListNode* temp=nullptr;
        if (size!=0){
            temp=groups.back();
            groups.pop_back();
        }
        ListNode dummy(0);
        ListNode* pointer = &dummy;
        for (int i = 0; i <groups.size(); ++i){
            pointer->next = reverseList(groups[i]);
            pointer = groups[i];
        }
        pointer->next = temp;
        return dummy.next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
