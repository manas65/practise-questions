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
        int v1=starter(i,n,s1);
        int v2=starter(j,m,s2);;
          
            if(v1>v2)return 1;
            else if(v2>v1) return -1;
             while(i<n || j<m){
             v1=helper(i,n,s1);
             v2=helper(j,m,s2);
             if(v1>v2)return 1;
            else if(v2>v1) return -1;
            }
        return 0;
        
    }
};