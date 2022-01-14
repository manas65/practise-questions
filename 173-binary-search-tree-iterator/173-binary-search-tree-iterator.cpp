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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
      TreeNode* temp=root;
        while(temp!=NULL){
            st.push(temp);
           temp=temp->left;
            }
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        if(top->right!=NULL){
            TreeNode* tempo=top->right;
            while(tempo!=NULL){
                st.push(tempo);
                tempo=tempo->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
     
        return st.size()!=0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */