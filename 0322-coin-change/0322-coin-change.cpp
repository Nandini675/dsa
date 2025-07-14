class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount+1,0);
         for(int t=0;t<=amount;t++){
             if(t%coins[0]==0){
                prev[t]= t/coins[0];
             }
             else prev[t]= INT_MAX;
             }
              for(int i=1;i<coins.size();i++){
                vector<int>curr(amount+1,0);
                 for(int t=0;t<=amount;t++){
                    int nottake= 0+ prev[t];
                    int take= INT_MAX;
                     if (coins[i] <= t && curr[t - coins[i]] != INT_MAX) {
    take = 1 + curr[t - coins[i]];
}

                     curr[t]= min(take, nottake);
                 }
                 prev= curr;
              }
              return prev[amount] == INT_MAX ? -1 : prev[amount];
    }
};