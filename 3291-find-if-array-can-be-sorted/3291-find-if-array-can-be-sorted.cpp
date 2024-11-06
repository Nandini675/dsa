using namespace std;
class Solution {

int countbits( int num){
    return bitset<32>(num).count();
}

public:
    bool canSortArray(vector<int>& nums) {
        int prevmax= INT_MIN;
        int currmax= nums[0];
        int currmin= nums[0];
        int setbits = countbits(nums[0]);
         for(int i=1;i<nums.size();i++){
             if(setbits == countbits(nums[i])){
                currmax= max(currmax, nums[i]);
                currmin= min(currmin, nums[i]);

             }
             else{
                if(currmin<prevmax) return false;
                 prevmax= currmax;
                  setbits= countbits(nums[i]);
                  currmax= nums[i];
                  currmin= nums[i];
             }
         }
         return currmin> prevmax;
    }
};