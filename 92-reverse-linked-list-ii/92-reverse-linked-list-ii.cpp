/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void rev(ListNode* & head,ListNode*& tail){
        
       ListNode* curr=head,*prev=NULL;
        
        while(curr!=NULL){
            ListNode* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
            // prev==tail
                if(prev==tail)break;
        }
        return;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right)return head;
        
       int i=1;
        ListNode* prev=NULL,*st=head,*end;
        
        while(i<left){
            prev=st;
            st=st->next;
            i++;
        }
        end=st;
        while(i<right){
            i++;
            end=end->next;
        }
        ListNode* endNext=end->next;
        
        rev(st,end);
        if(prev)prev->next=end;
        st->next=endNext;
        if(left==1)return end;
        return head;
        
        
    }
};