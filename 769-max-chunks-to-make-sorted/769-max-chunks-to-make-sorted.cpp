class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int amax=-1;
        int chunks=0;
        for(int i=0;i<arr.size();i++){
            amax=max(amax,arr[i]);// mai jis index pai hun agr waha tak ka max ele mera idx hai toh mai ek chunk bna sakta hun 
            if(amax==i) chunks++;
        }
       // if(amax==arr.size()-1) return chunks;//01243 last mai agr chunk update nhi hua toh
       
        // chunks++;
        return chunks;
    }
};