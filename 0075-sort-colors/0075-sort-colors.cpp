class Solution {
public:
    void sortColors(vector<int>& nums) {
            int n=nums.size();
        int low=0,high=n-1,i=0;
        while(i<=high){
            if(nums[i]==0 && i>=low){
                swap(nums[i],nums[low++]);
                i--;
            }else if(nums[i]==2){
                swap(nums[i],nums[high--]);
                i--;
            }
            i++;
        }
    }
};