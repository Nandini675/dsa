class Solution {
public:

void solve(int idx, int target,  vector<int>& ds,vector<vector<int>>& ans,vector<int>& arr){
    
     int n=arr.size();
    
     if (target==0){
         ans.push_back(ds);
         return;}
     
     // here we will be picking or not picimg a subsequene rather than index... toh 1st element subseq ko oth ,1,2,3,4..saare indexes bn skte hai
     for(int i=idx;i<n;i++){
         // ab agr koi 2 idx pr same lement rkha hai hua toh une mai se kisis ek ko hi piick krenge verna...uniqueness nhi aayegi subsequence mai...arr[1,1,1,2,2] toh 3rd idex ka 1st elemt bngya toh toh 4th idx capabale hai 2nd elemt of subseq bannae ka but 3rd aur 4th dono mai 2 pda hua hai toh es case ko dhyaan rkhe kuki 2nd idx pr 2 toh phli baar hi aarha hai toh usko le skte hai
          if(i>idx &&  arr[i]==arr[i-1]) continue;
          if(arr[i]>target) break;
          ds.push_back(arr[i]);
          solve(i+1,target-arr[i],ds,ans,arr);
          ds.pop_back();
     }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
          vector<vector<int>>ans;
          solve(0, target,ds,ans,candidates);
          return ans;
    }
};