class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        
        while(pq.size()>1){
            int largestStone=pq.top();
            pq.pop();
            int secondLargestStone=pq.top();
            pq.pop();
            int newStone=largestStone-secondLargestStone;
            if(newStone!=0)pq.push(newStone);
        }
        
        if(pq.size()==0)return 0;
        return pq.top();
    }
};