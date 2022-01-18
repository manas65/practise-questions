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
    void traverse(TreeNode* root,TreeNode*& prev,bool& ans){
        if(root==NULL)return;
        if(ans==false)return;
        
        traverse(root->left,prev,ans);
        if(prev==NULL)prev=root;
        else{
            if(prev->val>=root->val)ans=false;
        }
        prev=root;
        traverse(root->right,prev,ans);
        
        
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        bool ans=true;
        traverse(root,prev,ans);
        return ans;
    }
};