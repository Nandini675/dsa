class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0, j= 0;
        long long  pair=0;
        long long ans=0;
unordered_map<int,int>mpp;
while(j<nums.size()){
       pair+= mpp[nums[j]];
       mpp[nums[j]]++;
  while(pair>=k){
     ans+= (nums.size()-j);
     mpp[nums[i]]--;
     pair -= mpp[nums[i]];
     i++;
  }
  j++;
}
        return ans;
    }
};