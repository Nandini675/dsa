class Solution {
public:

int cntpartitions(vector<int>& nums,int max ){
    int sum=0, partition=1;
    int n= nums.size();
    for(int i=0;i<n;i++){
        if(sum + nums[i] <= max){
             sum  += nums[i];

        }
        else{
            partition+=1;
            sum= nums[i];
        }
    }
    return partition;

}
    int splitArray(vector<int>& nums, int k) {
int n= nums.size();
int s= *max_element(nums.begin(),nums.end());
int e=accumulate(nums.begin(),nums.end(),0);

while(s<=e){
    int mid= s+(e-s)/2;
  
    if(cntpartitions(nums,mid)>k ){
        s= mid+1;
    }
    else{
        e= mid-1;
    }

}

return s;

    }
};