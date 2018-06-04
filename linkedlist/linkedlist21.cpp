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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* h1=(l1->val<=l2->val)?l1:l2;
        ListNode* h2=(l1->val>l2->val)?l1:l2;
        while(h1!=NULL&h2!=NULL){
            ListNode* n1=h1->next;
            ListNode* n2=h2->next;
            while(n1!=NULL&&n1->val<=h2->val){h1=n1; n1=h1->next;}
            h1->next=h2;
            if(n1==NULL) return (l1->val<=l2->val)?l1:l2;
            while(n2!=NULL&&n2->val<=n1->val){h2=n2;n2=h2->next;} 
                h2->next=n1;    
                h1=n1;
                h2=n2;
        }    
        return (l1->val<=l2->val)?l1:l2;
    }
};
