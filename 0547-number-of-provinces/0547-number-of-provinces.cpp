class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true; // Mark the current node as visited
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false); // Use a vector instead of a variable-length array
        int cnt = 0; // Counter for the number of provinces (connected components)

        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // If the node is not visited
                cnt++;
                dfs(i, isConnected, visited); // Perform DFS
            }
        }

        return cnt;
    }
};
