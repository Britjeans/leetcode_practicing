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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head->next==NULL) return head;
        ListNode node(0);
        n=n-m;
        node.next=head;
        head=&node;
        while(m>1){
            head=head->next;
            --m;
        }
        ListNode* begin=head;
        ListNode* pre=head->next;
        ListNode* cur=head->next->next;
        while(n>0){
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
            --n;
        }
        ListNode* next=begin->next;
        begin->next=pre;
        next->next=cur;
        
        return node.next;
        
    }
};
