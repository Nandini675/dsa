class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // priority_queue<pair<int,pair<int,int>>,
        // vector<pair<int, pair<int,int>>>,
        // greater<pair<int, pair<int,int>>>>pq;
        // vector<pair<int,int>>adj(n);
         queue<pair<int, pair<int, int>>>q;//{stop,{cost,city}}
         vector<vector<pair<int, int>>> adj(n); // Declare adjacency list

for (auto it : flights) {
    adj[it[0]].push_back({it[1], it[2]});
}


        vector<int>price(n,1e9);
         price[src]=0;
          q.push({0,{0,src}});
          while(!q.empty()){

    auto it= q.front();
     int stop= it.first;
     int cost= it.second.first;
     int  city= it.second.second;
 q.pop();
 
       
 for( auto it: adj[city]){
     int   adjcity= it.first;
      int  pr=it.second;
if(price[adjcity]> pr+cost && stop <=k){
     price[adjcity]=pr+cost;
     q.push({stop+1,{pr+cost,adjcity}});
}
 }
  
          }
           if (price[dst]==1e9) return -1;
           else return price[dst];

    }
};