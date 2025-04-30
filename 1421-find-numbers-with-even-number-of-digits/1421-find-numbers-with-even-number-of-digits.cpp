class Solution {
public:
 string s="";
 int cnt=0;
    int findNumbers(vector<int>& nums) {
         for(int i:nums){
            s= to_string(i);
            if(s.length()%2==0) cnt++;
         }
         return cnt;
    }
};