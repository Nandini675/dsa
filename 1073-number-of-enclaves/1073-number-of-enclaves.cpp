class Solution {
     private:
    void dfs( int row, int col,vector<vector<int>>& grid,vector<vector<int>> & visited, int delrow[], int delcol[]){
        int n= grid.size();
       int m= grid[0].size(); 
         
         visited[row][col]=1;
        
         for(int i=0;i<4;i++){
              int nrow= row+ delrow[i];
              int ncol= col+ delcol[i];
               if(nrow>=0 && nrow<n&& ncol>=0 && ncol<m&& visited[nrow][ncol]==0 && grid[nrow][ncol]==1) 
              {
               dfs(nrow,ncol,grid,visited,delrow,delcol);}
            }
         }
public:
    int numEnclaves(vector<vector<int>>& grid) {
          int n= grid.size();
       int m= grid[0].size(); 

        vector<vector<int>> visited(n,vector<int>(m,0));
         int delrow[]={-1,0,1,0};
         int delcol[]={0,1,0,-1};
           for(int i=0;i<m;i++){
             if(!visited[0][i]&& grid[0][i]==1){
             dfs(0,i,grid,visited,delrow,delcol);}
             if(!visited[n-1][i]&& grid[n-1][i]==1){
             dfs(n-1,i,grid,visited,delrow,delcol);}

           }
        
        for(int i=0;i<n;i++){
             if(!visited[i][0]&& grid[i][0]==1){
             dfs(i,0,grid,visited,delrow,delcol);}
             if(!visited[i][m-1]&& grid[i][m-1]==1){
             dfs(i,m-1,grid,visited,delrow,delcol);}  
        }
        int cnt=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(!visited[i][j] && grid[i][j]==1){
                 cnt++;
                 
                 }

            }
         }
         return cnt;
    }
};