/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void serialize_helper(TreeNode* root, string & s){
        if(root==NULL){
            s+="N,";
            return;
                
        }
        s+=to_string(root->val);
        s+=",";
        serialize_helper(root->left,s);
        serialize_helper(root->right,s);
        return;
        
        
    }
    string serialize(TreeNode* root) {
        string s;
        
        serialize_helper(root,s);
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize_helper(vector<string>&v,int& idx){
        if(idx>=v.size() || v[idx]=="N"){
            idx++;
            return NULL;
        }
        
        int value=stoi(v[idx]);
        idx++;
        TreeNode* root=new TreeNode(value);
        root->left=deserialize_helper(v,idx);
        root->right=deserialize_helper(v,idx);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i=0;
        vector<string>v;
        while(i<data.length()){
            string temp="";
            while(data[i]!=','){
                temp+=data[i++];
            }
            v.push_back(temp);
            i++;
        }
        for(string ele:v)cout<<ele<<" ";
        int idx=0;
        return deserialize_helper(v,idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));