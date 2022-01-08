class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>map(26,0);
        
        for(char ch: s)map[ch-'a']++;
        
        for(int i=0;i<s.length();i++){
            if(map[s[i]-'a']==1)return i;
        }
        return -1;
    }
};