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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool isNull=false;
        q.push(root);
        while(q.size()!=0){
            int size=q.size();
            while(size-->0){
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL)isNull=true;
                else{
                    if(isNull)return false;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
    return true;
    }
};