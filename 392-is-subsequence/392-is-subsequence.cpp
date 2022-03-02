class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0,j=0;
        if(n==0)return true;
        while(j<m){
            if(s[i]==t[j]){
                i++;
                if(i==n)return true;
            }
            j++;
        }
    return false;
    }
};