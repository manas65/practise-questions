class Solution {
public:
    int helper(int &idx, int& n, string& s){
         int val=0;
        if(idx<n && s[idx]=='.'){
                idx++;
                while(s[idx]=='0')idx++;//skip leading zero
              while(idx<n &&s[idx]!='.' ){
                  val*=10;
                  val+=s[idx]-'0';
                  idx++;
              }  
                
            }
        return val;
    }
    
    int starter(int &idx, int& n, string& s){
        int val=0;
        while(s[idx]=='0')idx++;//skip leading zero
              while(idx<n && s[idx]!='.' ){
                  val*=10;
                  val+=(s[idx]-'0');
                  
                  idx++;
              }  
        return val;
    }
    
    
    int compareVersion(string s1, string s2) {
     
        int n=s1.size(),m=s2.size(),i=0,j=0;
        int a=starter(i,n,s1);
        int b=starter(j,m,s2);;
          
//               while(s1[i]=='0')i++;//skip leading zero
//               while(i<n && s1[i]!='.' ){
//                   a*=10;
//                   a+=(s1[i]-'0');
                  
//                   i++;
//               }  
                // cout<<a<<endl;
          
//                 while(s2[j]=='0')j++;//skip leading zero
//               while(j<m && s2[j]!='.' ){
//                   b*=10;
//                   b+=(s2[j]-'0');
//                   j++;
//               }  
            
            // cout<<b;
            if(a>b)return 1;
            else if(b>a) return -1;
             while(i<n || j<m){
             a=helper(i,n,s1);
             b=helper(j,m,s2);
             if(a>b)return 1;
             else if(b>a) return -1;
        }
        return 0;
        
    }
};