class Solution {
public:
    string triangleType(vector<int>& nums) {
         if (!isTri(nums)) return "none";
         if(isEqui(nums)) return "equilateral";
         if(isIsosceles(nums)) return "isosceles";
         return "scalene";
    }private:
    bool isTri(const vector<int>& nums) {
        return (nums[0] + nums[1] > nums[2] &&
                nums[0] + nums[2] > nums[1] &&
                nums[1] + nums[2] > nums[0]);
    }

    bool isEqui(const vector<int>& nums) {
        return nums[0] == nums[1] && nums[1] == nums[2];
    }

    bool isIsosceles(const vector<int>& nums) {
        return nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2];
    }

};