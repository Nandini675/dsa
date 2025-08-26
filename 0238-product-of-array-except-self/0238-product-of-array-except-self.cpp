class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int suf=1,pre=1;
         int n= nums.size();
         vector<int>ans(nums.size(),1);
         for( int i=0;i<nums.size();i++){
             ans[i]*= pre;
             pre *= nums[i];
             ans[n-1-i]*=suf;
             suf *= nums[n-1-i];
         }
         return ans;
    }
};