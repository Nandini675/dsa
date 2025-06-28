class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      int s=0,e= nums.size()-1;
          int kth;
           while(true){
            int idx= helper(nums,s,e);// we r sorting array into desecing order
           if(idx==k-1){
            kth= nums[idx];
             break;
           }
            if(idx<k-1){
                s= idx+1;
            }
            else{
                e= idx-1;
            }
           
           
           }
           return kth;
    }

    int helper( vector<int>&nums ,int left,int right){
         int pivot = nums[left];
         int i=left, j= right;
         while(i<j){
            
            while(nums[i]>=pivot&& i<=right-1){
                i++;
            }
            while(nums[j]<pivot && j>= left+1){
j--;
            }
             if(i<j) {swap(nums[i],nums[j]);}
                
                       }
                       swap(nums[left],nums[j]);
                       return j;

    }
};