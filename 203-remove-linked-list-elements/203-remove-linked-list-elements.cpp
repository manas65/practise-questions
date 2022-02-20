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
//     void remove(ListNode* & temp){
//         temp->next=temp->next->next;
//         // temp->next=NULL;
        
//     }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL )return NULL;
        while(head!=NULL && head->val==val)head=head->next;
        if(head==NULL)return head;
        ListNode* prev=head,*curr=head->next;
        
        while(curr!=NULL){
            if(curr->val==val){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
            
};