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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0) return head;
        int count=0;
        ListNode*h1=head;
        ListNode* h2=head;
        while(h2!=NULL){
            if(count==n+1){
                h2=h2->next;
                h1=h1->next;
                continue;
            }
            h2=h2->next;
            ++count;
        }
        if(count<n+1) return head->next;
        h1->next=h1->next->next;
        return head;        
    }
};
