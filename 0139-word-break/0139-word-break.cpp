class Solution {
public:
  bool solve(int idx, string s,set<string> &st,vector<int> &dp  ){
     int n=s.length();
     if(idx==n){
        return true;
     }
      if(dp[idx]!=-1) return dp[idx];
      for( int l=1;l<=n;l++){
      string   temp= s.substr(idx,l);
        if(st.count(temp)&& solve(idx+l,s,st,dp)){
            dp[idx]=true;
            return true;
        }
      }
      return dp[idx]= false;
     
  }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.length();
        vector<int>dp(n,-1);
        set<string>st;
         for( auto it: wordDict){
            st.insert(it);
         }
         return solve(0,s,st,dp);
    }
};