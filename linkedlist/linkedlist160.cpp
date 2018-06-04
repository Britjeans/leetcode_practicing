//slow version
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return NULL;
        ListNode* h1=headA;
        //create a circle
        while(h1->next!=NULL){
            h1=h1->next;
        }
        h1->next=headA;
        //loop1 
        ListNode* slow=headB;
        ListNode* fast=headB->next;
        
        while(fast!=NULL&&fast->next!=NULL&&slow->val!=fast->val){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast==NULL||fast->next==NULL){
            h1->next=NULL;
            return NULL;
        } 
        //loop2
        fast=headB;
        slow=slow->next;
        while(slow->val!=fast->val){
            slow=slow->next;
            fast=fast->next;                 
        }
        h1->next=NULL;
        return fast;  
        
    }
};
