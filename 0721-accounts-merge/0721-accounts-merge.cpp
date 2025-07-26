
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
         int n= accounts.size();
          unordered_map<string,int>mpmail;
          DisjointSet ds(n+1);
           for( int i=0;i<n;i++){
             for(int j=1; j<accounts[i].size();j++){
                string email= accounts[i][j];
                 if(mpmail.find(email)== mpmail.end()) mpmail[email]=i;
                 else ds.unionBySize( i, mpmail[email]);
             }
           }
           unordered_map<int, vector<string>>merg;
           for(auto it: mpmail){
             string email= it.first;
             int node= ds.findUPar(it.second);
              merg[ node].push_back(email);

           }
            vector<vector<string>>ans;
             for( auto [node, mail]: merg){
                 sort(mail.begin(), mail.end());
                  vector<string>temp={accounts[node][0]};
                   temp.insert(temp.end(), mail.begin(), mail.end());
                   ans.push_back(temp);

             }
             return ans;
    }
};