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
    //simple idea 
    int countNodes(TreeNode* root){
        if(root==NULL)return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    TreeNode* findNode(TreeNode* root, int val){
        if(root==NULL)return NULL;
        if(root->val==val)return root;
        // TreeNode*ans=NULL
       TreeNode*  left= findNode(root->left,val);
        if(left!=NULL)return left;
       TreeNode*  right= findNode(root->right,val);
        if(right!=NULL)return right;
        
        return NULL;
        
        
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
            if(root==NULL)return false;
        TreeNode*  redpos=findNode(root,x);
        int redleft=countNodes(redpos->left);
        int redright=countNodes(redpos->right);
        int parentcount=0;
        if(redpos!=root)parentcount=n-(redleft+redright+1);
        int bluecount=max({redleft,redright,parentcount});
        
        return bluecount>(n-bluecount);
    }
};