class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; i++) {
            int mini = INT_MAX, index = -1;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] < mini) {
                    mini = nums[j];
                    index = j;
                }
            }
            if(index != -1) {
                nums[index] = mini * multiplier;
            }
        }
        return nums;
    }
};
