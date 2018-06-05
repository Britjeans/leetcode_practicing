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
    ListNode*  Merge(ListNode* n1, ListNode* n2){
         if(n1==NULL) return n2;
         if(n2==NULL) return n1;        
        //star from the smallest
        if(n1->val>n2->val){
            ListNode* tmp=n1;
            n1=n2;
            n2=tmp;
        }
        ListNode node(0);
        node.next=n1;
        ListNode* pre=&node;
        ListNode* h=n1;
        while(n1!=NULL&&n2!=NULL){
            if(n1->val<=n2->val){
                pre=n1;                
                n1=n1->next;
                continue;
            }
            else{
                ListNode* next=n2->next;
                n2->next=n1;
                pre=pre->next=n2;
                n2=next;
            }            
        }
        while(n1!=NULL){
            pre=n1;
            n1=n1->next;
        }
        pre->next=n2;       
        return h; 
    }
    ListNode* sortList(ListNode* head) {     
        if(head==NULL||head->next==NULL) return head;
        ListNode* lo=head;
        ListNode* hi=head->next;
        while(hi!=NULL&&hi->next!=NULL){
            hi=hi->next->next;
            head=head->next;
        }        
        hi=head->next;
        head->next=NULL;
        lo=sortList(lo);
        hi=sortList(hi);
        return Merge(lo,hi);
    }
};
