class Solution {
public:
    bool checkValidString(string s) {
    
       stack<int>st1,st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*')st2.push(i);
            else if(s[i]=='(')st1.push(i);
            else{
                if(st1.size()!=0 && s[st1.top()]=='(' )st1.pop();
            else if(st2.size()!=0)st2.pop();
                else return false;
            
            }
            
        }
        while(st1.size()!=0){//open brackets left pair with star
            if(st2.size()==0)return false;
            if( st1.top()>st2.top())return false;
            st1.pop();
            st2.pop();
        }
        
        
        return true;
    }
};