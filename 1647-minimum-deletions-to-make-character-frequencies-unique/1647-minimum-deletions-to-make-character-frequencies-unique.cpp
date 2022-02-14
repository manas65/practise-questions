class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>charmap;
        unordered_map<int,int>freqmap;
        
        for(char ch:s)charmap[ch]++;
        for(pair<char,int> p:charmap)freqmap[p.second]++;
        int ans=0;
        for(auto it=charmap.begin();it!=charmap.end();it++){
            char mychar=it->first;
            int myfreq=it->second;
            if(myfreq==0)continue;
            while(freqmap[myfreq]>1){
                ans++;
                
                freqmap[myfreq]--;//decrement my freq from freqmap
                charmap[mychar]--;//decrement my freq from charmap
                // if(charmap[mychar]==0)charmap.erase(mychar);
                myfreq--;
                if(myfreq==0)break;
                freqmap[myfreq]++;
                
            }
            
        }
        
        return ans;
        
    }
};