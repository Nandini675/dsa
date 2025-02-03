class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n= nums.size();
        int inc,dec, maxi;
       maxi= inc=dec=1;

          for( int i=0;i<n-1;i++){
             if(nums[i]<nums[i+1]){inc++; dec=1;}
             else if(nums[i]>nums[i+1]){inc=1;dec++;}
             else{ inc=dec=1;}
          
        maxi= max(maxi,  max(inc,dec));
        }
        return maxi;
    }
};