class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n=  grid.size();
      int m= grid[0].size();
       if (n==1 && grid[0][0]==0) return 1;;
 queue<pair<int, pair< int,int>>>q;
 // edge case
  if( grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
  
vector<vector<int>>dist(n,vector<int>(m,1e9));
 dist[0][0]=1;
  int delrow[] ={0,-1,-1,-1,0,1,1,1};
  int delcol[]={-1,-1,0,1,1,1,0,-1};
    q.push({1,{0,0}});
    while(!q.empty()){
        auto it= q.front();
        q.pop();
          int dis=  it.first;
          int  r= it.second.first;
          int c= it.second.second;
           for( int i=0;i<8;i++){
             int newr= r+delrow[i];
              int newc= c+ delcol[i];
               if(newr>=0&& newr<n&& newc>=0&& newc<m && grid[newr][newc]==0&& dis+1< dist[newr][newc]){
                 dist[newr][newc]= dis+1;

               
                if(newr==n-1 && newc==n-1){
                    return dis+1;
                }
                q.push({1+dis,{newr,newc}});}
           }

    }


return -1;
    
    }
};