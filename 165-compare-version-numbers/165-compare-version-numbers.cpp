class Solution {
public:
    int compareVersion(string s1, string s2) {
     
        int n=s1.size(),m=s2.size(),i=0,j=0;
        int a=0,b=0;
          
              while(s1[i]=='0')i++;//skip leading zero
              while(i<n && s1[i]!='.' ){
                  a*=10;
                  a+=(s1[i]-'0');
                  
                  i++;
              }  
                // cout<<a<<endl;
          
                while(s2[j]=='0')j++;//skip leading zero
              while(j<m && s2[j]!='.' ){
                  b*=10;
                  b+=(s2[j]-'0');
                  j++;
              }  
            
            // cout<<b;
            if(a>b)return 1;
            else if(b>a) return -1;
        while(i<n || j<m){
           a=0;
             b=0;
            if(i<n && s1[i]=='.'){
                i++;
                while(s1[i]=='0')i++;//skip leading zero
              while(i<n &&s1[i]!='.' ){
                  a*=10;
                  a+=s1[i]-'0';
                  i++;
              }  
                
            }
            if(j<m && s2[j]=='.'){
                j++;
                while(s2[j]=='0')j++;//skip leading zero
              while(j<m && s2[j]!='.'){
                  b*=10;
                  b+=s2[j]-'0';
                  j++;
              }  
                
            }
            if(a>b)return 1;
            else if(b>a) return -1;
        }
        return 0;
        
    }
};