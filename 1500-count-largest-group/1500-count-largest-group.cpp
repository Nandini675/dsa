class Solution {
public:
    int countLargestGroup(int n) {
       unordered_map<int,int>mpp;
       int maxi=0;
       for( int i=1;i<=n;i++){
        int sum= digitsum(i);
        mpp[sum]++;
        maxi= max(maxi,mpp[sum]);
       }
       int cnt=0;
       for( auto it:mpp){
        if(it.second==maxi){
cnt++;
        }
       }
       return cnt;}
     private: int digitsum(int num){
         int sum=0;
         while(num>0){
            sum+= num%10;
            num/=10;
         }
         return sum;
     }
    
};