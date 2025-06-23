class Solution {
public:
  
      void dfs(int node, vector<int>&vis, vector<vector<int>>&adjList){
        vis[node] = 1;
        for (auto edge : adjList[node]) {
            if (!vis[edge]) {
                dfs(edge, vis, adjList);
            }
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<vector<int>> adjList(n);
        for (int i = 0; i < connections.size(); i++) {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, vis, adjList);
            }
        }

        return components - 1;
    }

};