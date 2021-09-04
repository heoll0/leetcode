#include<vector>
using namespace std;


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        do{
            if(fast == NULL) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);

        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
        
    }
};