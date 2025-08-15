class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         //  finding the brek point - o(n)
         int idx=-1;
          int n= nums.size();
          for( int i=n-2;i>=0;i--){
              if(nums[i]<nums[i+1]){
                 idx=i;
                 break;
              }
          }
          if(idx==-1) {reverse(nums.begin(),nums.end()); return;}
          // find elemnt just slightly graeer than nums[idx]
           for(int i=n-1;i>=0;i--){
             if( nums[i]>nums[idx]){
                swap(nums[i], nums[idx]);
                break;
             }
           }
            // ab remaining waale no ko  sort kr denge kuki vo phle se hi i ek order mai arrange hai toh just reverse kro
             reverse(nums.begin()+idx+1, nums.end());
    }
};