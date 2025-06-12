class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {  // Loop till second last element
            maxi = max(maxi, abs(nums[i+1] - nums[i]));  // Compare adjacent elements
        }
        if( maxi< abs(nums[n-1]- nums[0])) return  abs(nums[n-1]- nums[0]);
            
        
      else  return maxi;
    }
};
