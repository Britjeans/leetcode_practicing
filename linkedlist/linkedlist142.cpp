/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return NULL;      
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow->val!=fast->val){
            if(fast==NULL||fast->next==NULL) return NULL;
            fast=fast->next->next;
            slow=slow->next;
            if(fast==NULL||fast->next==NULL) return NULL;
        }
        slow=slow->next;
        fast=head;
        while(fast->val!=slow->val){
            fast=fast->next;
            slow=slow->next;           
        }
        return slow;
        
    }
};
