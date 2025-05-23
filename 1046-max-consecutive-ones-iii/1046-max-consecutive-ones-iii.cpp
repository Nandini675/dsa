class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0; int n= nums.size();
         int  maxi=0;
         int cntzero=0;
while(r<n){
     if(nums[r]==0) {cntzero++;}
     if(cntzero>k){
  if(nums[l]==0) cntzero--;
  l++;
     }
     if(cntzero<=k) maxi= max(maxi, r-l+1);
     r++;

} return maxi;
    }
};