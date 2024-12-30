class Solution {
public:
    int lengthOfLastWord(string s) {
         int e= s.length()-1;
         while(e>=0&& s[e]==' '){
            e--;
         }
         int st=e;
         while(st>=0 && s[st]!=' '){
            st--;
         }
         return e-st;
    }
};