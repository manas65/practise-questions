class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        if(grid[0][0]==1 ||grid[n-1][m-1]==1)return -1;
        q.push({0,0});
        int level=1;
        //mark
        grid[0][0]=1;
        //bfs
        while(q.size()!=0){
            int size=q.size();
            while(size--){
                pair<int,int> idx=q.front();
                q.pop();
                int x=idx.first;
                int y=idx.second;
             //check if reached at ans;
                if(x==n-1 && y==m-1)return level;
                
                //add all neighbours to queue
                
                for(int i=0;i<dir.size();i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(ny>=0 && ny<m && nx>=0 && nx<n && grid[nx][ny]!=1 ){
                        //mark
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
                
            }
            level++;
        }
        
        return -1;
    }
};