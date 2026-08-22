class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;


        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }


        if (n == length) return head->next;

        temp = head;

        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
