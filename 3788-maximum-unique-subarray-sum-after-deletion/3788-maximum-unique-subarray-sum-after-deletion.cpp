class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
       
 for(int i=0;i<n;i++){
    st.insert(nums[i]);

 }
 int mini= INT_MIN;
 int sum=0;
for(auto i: st){
     if(i>0) sum+=i;
     else  mini= max(mini,i);
}
       

        return  sum==0? mini: sum;
    }
};
