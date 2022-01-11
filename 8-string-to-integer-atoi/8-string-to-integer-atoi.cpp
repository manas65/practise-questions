class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        if(n==0)return 0;
        
        int i=0;
        bool isNeg=false;
     //leading white space ignore  //leading 0 ignore
        while(s[i]==' ')i++; //ignore whitespace
        if(s[i]=='-' || s[i]=='+' ){//sign
                if(s[i]=='-')isNeg=true;
                i++;
               }
        while(s[i]=='0')i++;
        if(i==n || s[i]=='+' || s[i]=='-')return 0;
        
                  
       int ans=0;
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                 if(ans >  INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7))
                     if(isNeg)return INT_MIN;
                    else return INT_MAX;
                ans=ans*10 + (s[i]-'0');
            }   
            else break;
            i++;
        }
        if(isNeg)ans=-ans;
      
        
    return ans;
    }
};
