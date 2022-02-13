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
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int leftHeight=1,rightHeight=1;
        TreeNode* temp=root->left;
        while(temp!=NULL){
            leftHeight++;
            temp=temp->left;
        }
         temp=root->right;
        while(temp!=NULL){
            rightHeight++;
            temp=temp->right;
        }
        if(leftHeight==rightHeight)return   pow(2,leftHeight)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};