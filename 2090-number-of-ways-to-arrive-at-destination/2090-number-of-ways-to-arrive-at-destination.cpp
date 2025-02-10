
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // Min-heap (Dijkstra’s priority queue)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Distance and ways arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        const int MOD = 1e9 + 7;

        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue; // Ignore outdated distance

            for (auto &[adjNode, edgeWeight] : adj[node]) {
                long long newDist = d + edgeWeight;

                // If a shorter path is found
                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];  // Reset path count
                    pq.push({newDist, adjNode});
                }
                // If another shortest path is found
                else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};
