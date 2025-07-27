class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n= nums.size();
        int left=0 ;// keep a track ki prev distinct elemt konsa hai
        int cnt=0;
        for(int i=1;i<n-1;i++){
             if(nums[i]!= nums[i+1]){
                if(nums[i]<nums[left]&& nums[i]<nums[i+1]||
                nums[i]>nums[left]&& nums[i]>nums[i+1]
                ) {cnt++;}
                left=i;
             }

        }

       return cnt;
    }
};