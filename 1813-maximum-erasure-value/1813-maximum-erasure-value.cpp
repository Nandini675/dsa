class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int l = 0, r = 0, sum = 0, maxSum = 0;

        while (r < nums.size()) {
            // if duplicate found, shrink window from left
            while (seen.count(nums[r])) {
                seen.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            // insert new unique number
            seen.insert(nums[r]);
            sum += nums[r];
            maxSum = max(maxSum, sum);
            r++;
        }

        return maxSum;
    }
};
