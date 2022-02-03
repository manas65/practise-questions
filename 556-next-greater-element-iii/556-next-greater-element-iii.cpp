class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(s.length()==1)return -1;
        //start from 2nd last
        int idx;
        for( idx=s.length()-2;idx>=0;idx--){
            if(s[idx]<s[idx+1])break;
        }
        if(idx==-1)return -1;
       
        reverse(s.begin()+idx+1,s.end());//pivot point ka baad soted hona chahiya
        
        for(int j=idx+1;j<s.length();j++){
            if(s[j]>s[idx]){
                swap(s[j],s[idx]);
                break;
            }
        }
        
        long ans=stol(s);
        
        if(ans==n || ans>INT_MAX)return -1;
        
        return ans;
    }
};