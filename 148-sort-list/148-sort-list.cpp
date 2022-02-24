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
    ListNode* mid_finder(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* head1,  ListNode*head2){
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        
        ListNode* dummyhead= new ListNode(-1);
        ListNode* prev=dummyhead;
        ListNode* curr1=head1,*curr2=head2;
        
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<=curr2->val){
                prev->next=curr1;
                curr1=curr1->next;
            }
            else{
                prev->next=curr2;
                curr2=curr2->next;
            }
            prev=prev->next;
        }
        if(curr1)prev->next=curr1;
        if(curr2)prev->next=curr2;
        
        ListNode* myhead=dummyhead->next;
        dummyhead->next=NULL;
        delete dummyhead;
        return myhead;
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)return head;
        
        ////find mid
        ListNode* mid=mid_finder(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;
                
        
        
        //leftr sort
        ListNode* left=sortList(head);
        //right sort
        ListNode* right=sortList(nhead);
        //return merged list
        return merge(left,right);
    }
};