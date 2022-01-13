class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        if(s.size()==1)return s[0];
        string ans="";
        int m=0,n=0;
        while(m<s[0].length() && n<s[1].length() ){
            if(s[0][m]==s[1][n])ans+=s[0][m],m++,n++;
            else break;
        }
        // cout<<ans;
        
        for(int idx=2;idx<s.size();idx++){
            string tempans="";
            int i=0,j=0;
            while(i<ans.length() && j<s[idx].length()){
                if(ans[i]==s[idx][j])tempans+=ans[i],i++,j++;
                else break;
            }
            ans=tempans;
            
        }
    return ans;
    }
};