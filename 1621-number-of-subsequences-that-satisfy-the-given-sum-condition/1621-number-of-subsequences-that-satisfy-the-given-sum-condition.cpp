class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m=1e9 + 7;
        // hum array ko sort krdenge taki max and min nikalna asan ho ...sortimg se releivative order chnage ho rha hao but yha hum subsequmve print nhi kr rhe we r just check the no of subject  having minelelm as arr[i];
        int n= nums.size();
         sort(nums.begin(),nums.end());
         int s=0, e= nums.size()-1;
         int cnt=0;
         vector<int>pow2(n+1,1); //if n=3 [1,1,1,1]
           for( int i=1;i<=n;i++){
             pow2[i]= (1LL*pow2[i-1]*2)%m; //[1,2,4,8]
           }
         while(s<=e){
             if(nums[s]+nums[e]<=target){
                int noofsubseq= pow2[e-s];  // (2^n)% mod
                cnt= ( cnt+1LL*noofsubseq)%m;
                   s++;
             }
             else{
                e--;
             }
         }
         return cnt;
    }
};