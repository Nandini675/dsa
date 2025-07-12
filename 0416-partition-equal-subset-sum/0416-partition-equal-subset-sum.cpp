class Solution {
public:
 bool solve(vector<int>& nums, int k){
     vector<bool>prev(k+1,false);
     if(nums[0]<=k) prev[nums[0]]=true;
      for(int i=1;i<nums.size();i++){
        vector<bool>curr(k+1,false);
        for(int target=1;target<=k;target++){
             bool nottake= prev[target];
             bool take= false;
             if(nums[i]<=target){
                take= prev[target-nums[i]];
             }
             curr[target]=take|nottake;
        }
        prev= curr;
      }
       return prev[k];
 }
    bool canPartition(vector<int>& nums) {
       int totalsum=0;
        for(int i=0;i<nums.size();i++ ) {
            totalsum+=nums[i];}
             if(totalsum%2!=0) return false;
             return solve(nums,totalsum/2);
    }
};