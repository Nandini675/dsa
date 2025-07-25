class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n= nums.size();
        int maxsum=0, maxi=INT_MIN;
         for(int i =0;i<n;i++){
             maxi= max(maxi,nums[i]);}
            if( maxi<0) return maxi;
        for(int i =0;i<n;i++){
        
 set<int>st;int sum=0;
for(int j=i;j<n;j++){
     if(nums[j]<0) continue;
     if(st.find(nums[j])!=st.end()) continue;
     st.insert(nums[j]);
     sum+= nums[j];
    
}
 maxsum= max(maxsum, sum);
        }
        return maxsum;
    }
};