/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root,TreeNode*& a,TreeNode*& b,TreeNode*& prev) {
        if(root==NULL)return;
        
        traverse(root->left,a,b,prev);
        if(prev==NULL)prev=root;
        else if(prev->val>root->val){
            if(a==NULL)a=prev,b=root;
            else b=root;
        }
        prev=root;
        traverse(root->right,a,b,prev);
        
    }
    
    
    void recoverTree(TreeNode* root) {
        TreeNode* a=NULL;
        TreeNode* b=NULL;
        TreeNode* prev=NULL;
        traverse(root,a,b,prev);
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
        return;
    }
};