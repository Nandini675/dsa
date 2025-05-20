class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       vector<int>diff(nums.size()+1,0)  ; //[0,0,0,0,0,0]
        int n= nums.size();
        for( auto & it: queries){
             diff[it[0]]++;
              if(it[1]+1<n)
             diff[it[1]+1]--;
              
        }
        int cnt=0;
         for( int i=0;i<n;i++){
             cnt+= diff[i];
             if(nums[i]> cnt) return false;
         }
          return true;
    }
};