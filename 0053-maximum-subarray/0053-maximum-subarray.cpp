class Solution {
public:
    // [5,4,-1,7,8]

    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
   int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
         
            //  for(int j=i;j<nums.size();j++){
            //     sum+= nums[j];
            sum += nums[i];
           

            if (maxi < sum) {
                maxi = sum;
            }

             if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};