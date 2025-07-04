class Solution {
public:
  void solve(  int idx, int sum,  vector<int>& ds,vector<vector<int>>& ans,int n , int k, int start){
     //base case
      if(idx==k) {
         if(sum==n){
            ans.push_back(ds);
         }
         }
          for( int i=start;i<=9;i++) // mai combination  1 se likr 9 tak kisi bhi no se start kr skti hu
          {
             if(sum+i>n ) break;
             ds.push_back(i);
             solve(idx+1,sum+i,ds,ans,n,k,i+1);
             
             ds.pop_back();
           
        
          }
 }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>> ans;
        solve(0,0,ds,ans,n,k,1);
        return ans;
    }
};