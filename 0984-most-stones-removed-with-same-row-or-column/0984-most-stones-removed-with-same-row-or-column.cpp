class Solution {
public:
void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        vis[node] = 1;
        for(auto edge: adj[node]){
            if(!vis[edge]) dfs(edge, vis, adj);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
         vector<vector<int>>adj(n);
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 if(stones[i][0]== stones[j][0]|| stones[i][1]== stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                 }

            }
         }
             int connect= 0;
             vector<int>vis(n,0);
              for( int i=0;i<n;i++){
                 if(!vis[i]){
                    connect++;
                    dfs(i,vis,adj);
                 
              }

         }
          return n- connect;

    }
};