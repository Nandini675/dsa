class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        // adj list
        for( auto it: times){
             adj[it[0]].push_back({it[1],it[2]});   //[{target,tym}]
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;// {target, tym}
         vector<int>time(n+1,1e9);
         time[k]=0;
          pq.push({0,k});
          while(!pq.empty()){
             auto it= pq.top();
             int ty = it.first;
             int node= it.second;
             pq.pop();
              for( auto it: adj[node]){
                 int adjno= it.first;
                 int edw=it.second;
                 if(time[adjno]> ty+edw){
time[adjno]=ty+edw;
pq.push({ty+edw,adjno});
                 }
                 
              }
          }
           int maxi= *max_element(time.begin()+1,time.end());
           return (maxi == 1e9) ? -1 : maxi;

    }
};