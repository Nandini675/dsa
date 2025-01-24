class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          int n= graph.size();
          vector<vector<int>>reversegraph(n);
vector<int>outdegree(n,0);
          // making a reverse graph
           for( int i=0;i<n;i++){
            for( auto it: graph[i]){
                 reversegraph[it].push_back(i);
            }
            outdegree[i]= graph[i].size();

           }
           queue<int>q;

             for( int i=0;i<n;i++){
                 if( outdegree[i]==0)
                 q.push(i);
             }
             vector<int>safe;
 while(!q.empty()){
     int node= q.front();
     q.pop();
safe.push_back(node);
for( auto it: reversegraph[node]){
    outdegree[it]--;
    if( outdegree[it]==0){
        q.push(it);
    }
}
 }
   sort(safe.begin(), safe.end());

       return safe;    
    }
};