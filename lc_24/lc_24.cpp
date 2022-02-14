class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* pre = nullptr;
        ListNode* next;
        while( curr != nullptr){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    return pre;
    }
};