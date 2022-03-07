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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list2)return list1;
        else if(!list1) list2;
        
        ListNode* dummy= new ListNode(-1);
        
        ListNode* curr1=list1,*curr2=list2,*prev=dummy;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<curr2->val){
                prev->next=curr1;
                prev=curr1;
                curr1=curr1->next;
                
            }
            else {
                prev->next=curr2;
                prev=curr2;
                curr2=curr2->next;
                
            }
        }
        if(!curr1)prev->next=curr2;
        if(!curr2)prev->next=curr1;
        
        return dummy->next;
        
    }
};