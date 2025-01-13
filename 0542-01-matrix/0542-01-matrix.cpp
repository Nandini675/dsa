class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n= mat.size();
       int m= mat[0].size();
vector<vector<int>>visi(n,vector<int>(m,0));
vector<vector<int>>dist(n,vector<int>(m,0));
queue<pair<pair<int,int>,int>>q;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
         if(mat[i][j]==0){
            visi[i][j]=1;
            q.push({{i,j},0});
         }
    }
}
    while(!q.empty()){
         int row= q.front().first.first;
         int col= q.front().first.second;
         int steps= q.front().second;
         dist[row][col]=steps;
q.pop();

          int delrow[]= {-1,0,1,0};
          int delcol[]={0,1,0,-1};
for(int i=0;i<4;i++)
{
     int nrow= row+delrow[i];
     int ncol= col+ delcol[i];
      if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && visi[nrow][ncol]==0 ){
        visi[nrow][ncol]=1;
         q.push({{nrow, ncol},steps+1});
      }
}

    }
  return dist;  
}

 
};