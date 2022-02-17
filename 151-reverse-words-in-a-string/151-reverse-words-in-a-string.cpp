class Solution {
public:
    string reverseWords(string s) {
        // i and j think like this i reads and j writes i scan krka right position pai jata hai and j shi position pai kaam krta hai
        
        int i=0,j=0,n=s.length();
        while(i<n){
            while(i<n && s[i]==' ')i++;//skip spaces and find the word
            
            if(i<n && j>0 )s[j++]=' ';//a word is finished
            int start=j;
            while(j<n && i<n && s[i]!=' '){
                //write to s with j
                s[j++]=s[i++];
            }
            reverse(s.begin()+start,s.begin()+j);
            
            
        }
        s.resize(j);
         reverse(s.begin(),s.end());
        return s;
        
    }
};