class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int l=0;int r=0; int oddcnt=0;int res=0;
        while(r<nums.size()){
             if(nums[r]%2==1)  oddcnt++;
             res+= mpp[oddcnt-k];
             mpp[oddcnt]++;
             r++;
        }
        return res;
    }
};