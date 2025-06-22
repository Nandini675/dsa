class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n= s.length();
      int  rem = (n % k == 0) ? 0 : k - (n % k);
        for(int i=0;i<rem;i++){
            s+=fill;
        }
        vector<string>st;
        for(int i=0;i<(n+rem);i+=k){
         string sub= s.substr(i,k);
         st.push_back(sub);
         
        }
        return st;
    }
};