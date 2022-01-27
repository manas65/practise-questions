class Solution {
public:
    bool kahnalgo(vector<vector<int>>& graph){
        queue<int>q;
        vector<int>indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[graph[i][j]]++;
            }
        }
        int count=0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        while(q.size()!=0){
            int size=q.size();
            while(size-->0){
                int rvtx=q.front();
                q.pop();
                count++;
                for(int i=0;i<graph[rvtx].size();i++){
                    indegree[graph[rvtx][i]]--;
                   if( indegree[graph[rvtx][i]]==0)q.push(graph[rvtx][i]);
                }
            }
        }
        return count==graph.size();
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        return kahnalgo(graph);
    }
};