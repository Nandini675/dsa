class Solution {
public:
void solve(int i,int target,vector<int>& arr, vector<int>&ds,vector<vector<int>> &ans){
     //base case
      if(i==arr.size()){
         if (target==0)
         {ans.push_back(ds);}
   return;
      }
      //  hrrr indx pr 2 choices hai ya toh pick or not pick ans ek element ko tab tak pick kr skte hai if arr[i]< target
       if(arr[i]<=target){
        ds.push_back(arr[i]);
        solve(i,target- arr[i],arr,ds,ans);
        ds.pop_back();
       }
        solve(i+1,target,arr,ds,ans);
   
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int>ds;
       vector<vector<int>> ans;
       solve(0,target,candidates,ds,ans);
       return ans;

    }
};