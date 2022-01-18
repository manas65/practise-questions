/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*>q;
        if(root==NULL)return NULL;
        q.push(root);
        while(q.size()!=0){
            int size=q.size();
            while(size--){
                Node* top=q.front();
                q.pop();
                if(top->left!=NULL)q.push(top->left);
                 if(top->right!=NULL)q.push(top->right);
                if(top->left!=NULL)
                top->left->next=top->right;
                if(top->right!=NULL &&  top->next!=NULL)
                top->right->next=top->next->left;
                
                
            }
        }
        return root;
    }
};