class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    sort( nums.begin(),nums.end());
         int l= 0; int r=0;
         long long sumofcurrwindow=0; int ans=0;
          int target=0;
           while(r<nums.size()){
             target= nums[r];
             sumofcurrwindow+= target;
              while((1ll*(r-l+1)*target-sumofcurrwindow)> k){
                 sumofcurrwindow-= nums[l];
                l++;
                
              }
              ans= max( ans, r-l+1);
              r++;

           }
           return ans;
    }
};