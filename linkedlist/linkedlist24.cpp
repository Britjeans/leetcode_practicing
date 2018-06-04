//beat 100% solution
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* h=head;
        ListNode* res=head->next;
        ListNode* next=head->next; 
        while(h!=NULL&&next!=NULL){
            ListNode* newHead=next->next;
            next->next=h;
            if(newHead!=NULL){
                if(newHead->next!=NULL){
                    h->next=newHead->next;     
                    h=newHead;
                    next=h->next;
                }
                else{
                    h->next=newHead;
                    return res;
                }    
            }
            else{
                h->next=NULL;
                return res;
            }
        }
        return res;
    }
};
