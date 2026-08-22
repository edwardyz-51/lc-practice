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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        while (head){
            arr.push_back(head);
            head = head->next;
        }
        int l = 0, r = arr.size()-1;
        ListNode dummy;
        ListNode* cur = &dummy;
        while (l<=r){
            cur->next = arr[l];
            l++;
            cur = cur->next;
            if (l>r) break;
            cur->next = arr[r];
            r--;
            cur = cur->next;
        }
        cur->next = nullptr;
        head = dummy.next;
    }
};
