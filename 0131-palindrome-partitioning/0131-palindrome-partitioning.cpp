class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>ds;
        solve(0,s,ds,res);
        return res;
    }
     void solve(int idx, string& s, vector<string>&ds, vector<vector<string>>&res){
         int n= s.length();
         if(idx==n) {
             res.push_back(ds);
             return ;
         }
         for(int i= idx;i<n;i++){
             if(ispalindrome(s,idx,i)){
             ds.push_back(s.substr(idx,i-idx+1));
             solve(i+1,s,ds,res);
             ds.pop_back();
             }
         }

     }
      bool ispalindrome(string& s, int start, int end){
        while(start<=end){
         if(s[start++]!= s[end--]) return false;
         }
         return true;
      }

};