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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        stack<ListNode*> s;
        ListNode* res=NULL;
        int count=1,i=1;
        s.push(head);
        head=head->next;
        while(head!=NULL){
            ++count;
            ++i;
            int val=s.top()->val;
            if(val<=head->val) {
                s.push(head);
                head=head->next;
                continue;
            }
            s.top()->next=head->next;           
            while(!s.empty()){
                res=s.top();
                int val=s.top()->val;
                if(val<=head->val) {
                    head->next=s.top()->next;
                    s.top()->next=head;
                    s.push(head);
                    while(i<count){
                        ++i;
                        head=head->next;
                        s.push(head);                      
                    }
                    break;
                }
                s.pop();
                --i;
            }
            if(s.empty()){
                head->next=res;
                s.push(head);
                while(i<count){
                        ++i;
                        head=head->next;
                        s.push(head);                      
                }
            }

            head=head->next;
        }
        
        while(!s.empty()){
            res=s.top();
            s.pop();
        }
        return res;
    }
};


//faster version 

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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* tmp=head;
        ListNode* pre=head;
         ListNode* preNode=NULL;
        head=head->next;
        while(head!=NULL){
            ListNode* next=head->next;  
            preNode=head;
            if(pre->val>head->val){
                preNode=pre;
                pre->next=head->next;
                pre=tmp; 
                if(pre->val>head->val) {head->next=pre;tmp=head;}
                else{
                    while(pre->next->val<=head->val){
                        pre=pre->next;
                    }
                    head->next=pre->next;
                    pre->next=head;       
                }    
            }
            pre=preNode;
            head=next;            
        }
        return tmp;
    }
};



