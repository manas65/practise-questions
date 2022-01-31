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
    
    void travel(TreeNode* root, int maxVal,int &count){
        if(root==NULL)return;
        
        if(root->val>=maxVal){
            count++;
            maxVal=max(maxVal,root->val);
        }
        travel(root->left,maxVal,count);
        travel(root->right,maxVal,count);
    }
    
    int goodNodes(TreeNode* root) {
        int count=0;
        travel(root,-1e8,count);
        return count;
    }
};