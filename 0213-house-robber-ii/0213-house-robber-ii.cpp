class Solution {
public:
 int helper(vector<int>&nums){
     int prev1=nums[0];
     int prev2=0;
     for( int i=1;i<nums.size();i++){
      int pick= nums[i]+ prev2;
      int notpick= 0+ prev1;
     int curr= max(pick,notpick);
     prev2= prev1;
     prev1= curr;
 }
 return prev1;
 }
 
    int rob(vector<int>& nums) {
         vector<int> temp1, temp2;
         int n= nums.size();
         if(n==1) return nums[0];
         for(int i=0;i<n;i++){
          if(i!=0) temp1.push_back(nums[i]);
           if(i!=n-1) temp2.push_back(nums[i]);}
            return max(helper(temp1), helper(temp2));
    }
};