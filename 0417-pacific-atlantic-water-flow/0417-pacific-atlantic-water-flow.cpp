class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         int delr[4]={-1,0,1,0};
         int delc[4]={0,1,0,-1};
           int n= heights.size();
            int m= heights[0].size();
          vector<vector<bool>> pacific_vis(n,vector<bool>(m,0));
          vector<vector<bool>> atlan_vis(n,vector<bool>(m,0));
            queue<pair<int,int>>pac;// row,col
             queue<pair<int,int>>atlan;
              for( int i=0;i<n;i++){
                // first col pacific ko pani dega
                pac.push({i,0});
                pacific_vis[i][0]=1;
                // last col  pani jayega= atlantic
                atlan.push({i,m-1});
                atlan_vis[i][m-1]=1;

              }
               for( int j=1;j<m;j++){
                // phli row  se pani jaayega pacific ko except the fist block
                 pac.push({0,j});
                 pacific_vis[0][j]=1;}
                 // last row
                  for( int j=0;j<m-1;j++){
                 atlan.push({n-1,j});
                 atlan_vis[n-1][j]=1;
               }
               // pacific ocean
                while(!pac.empty()){
                     auto curr= pac.front();
                      int r= curr.first;
                      int c=curr.second;
                       int val= heights[r][c];
                       pac.pop();
                        for(int i=0;i< 4;i++){
                             int nr= r+delr[i];
                              int nc= c+ delc[i];
                               if( nc>=0&& nr>=0 && nr<n&& nc<m && pacific_vis[nr][nc]==0 && 
                                heights[nr][nc]>=val) {
                                 pacific_vis[nr][nc]=1;
                                  pac.push({nr, nc});
                                }
                               
                        }

                }
                // for atlantic
                while(!atlan.empty()){
                     auto curr= atlan.front();
                      int r= curr.first;
                      int c= curr.second;
                       int val= heights[r][c];
                       atlan.pop();
                        for(int i=0;i< 4;i++){
                             int nr= r+delr[i];
                              int nc= c+ delc[i];
                               if( nc>=0&& nr>=0 && nr<n&& nc<m && atlan_vis[nr][nc]==0 && 
                                heights[nr][nc]>=val) {
                                 atlan_vis[nr][nc]=1;
                                  atlan.push({nr, nc});
                                }
                               
                        }

                }
                vector<vector<int>> ans;
                 for( int i=0;i<n;i++){
                     for( int j=0;j<m;j++){
                         if(pacific_vis[i][j]==1 && atlan_vis[i][j]==1)
                           ans.push_back({i,j});
                     }
                 }

           return ans;  
    }
};