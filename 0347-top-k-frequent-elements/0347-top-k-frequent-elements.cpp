class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n= nums.size();
         for( int i=0;i<n;i++){
            freq[nums[i]]++;
         }
    priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>>pq;
     for(auto it: freq){
         int  num=it.first;
         int cnt= it.second;
          pq.push({cnt,num});
          if(pq.size()>k){
            pq.pop();
          }
     
      }
      vector<int>ans;
      while(!pq.empty()){
          ans.push_back(pq.top().second);
         pq.pop();
      }
 return ans;
    }
};