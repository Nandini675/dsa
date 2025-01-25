class Solution {

    private:
     bool dfs( int node,vector<int>&visited ,vector<vector<int>>&adj, stack<int>&st){
         
        
          visited[node]=1;
           for( auto it: adj[node]){
         if(visited[it]==0){
            
         if(dfs( it, visited,adj,st)) return true;// cycle detected
        
        }
        else if( visited[it]==1) return true; // cycle detected

           }
           visited[node]=2;
           st.push(node);
            return false;
     }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      int n= numCourses;
      vector<vector<int>> adj(n);
      for( auto it:prerequisites){
         adj[(it[1])].push_back(it[0]);
      }
      stack<int> st;
      vector<int>visited(n,0);
 for( int i=0;i<n;i++){
     if(!visited[i]){
        if(dfs( i, visited, adj, st)){
            return{};
        }
     }
 }
 vector<int>ans;
 while(!st.empty()){
     ans.push_back(st.top());
     st.pop();
 }
 return ans;
    }
};