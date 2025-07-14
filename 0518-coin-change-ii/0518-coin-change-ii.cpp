class Solution {
public:
 const long long MOD = 1e9 + 7;
    int change(int amount, vector<int>& coins) {
      int amt= amount;
       vector<long long>prev(amt+1,0)  ;
       for(int i=0;i<=amt;i++){
        prev[i]= (i%coins[0]==0);
       }
        for(int i=1;i<coins.size();i++){
             vector<long long>curr(amt+1,0);
             for(int t=0;t<=amt;t++){
                 long long notpick= prev[t];
                 long long  pick=0;
                 if(coins[i]<=t){ pick= curr[t-coins[i]];}
                 curr[t]= pick+notpick %MOD;

             }
             prev=curr;
        }
        return(int) prev[amt];
    }
};