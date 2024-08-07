#include<cmath>
class Solution {
public:
int  sumly(vector<int>& nums, int div){
    int sum=0;
    int n= nums.size();
    for(int i=0;i<n;i++){
 sum += ceil((double)(nums[i])/ (double)(div));
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        if(n>threshold) return -1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi= max( maxi, nums[i]);
          

        }
        int s=1,e= maxi;
        int mid= s+(e-s)/2;
        while(s<=e){
             if(sumly(nums,mid)<=threshold){
                e= mid-1;
             }
             else{ s= mid+1;}
          mid= s+(e-s)/2;   
        }
        return s;
    }
};