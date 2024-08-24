class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int opbr=0;
     for(char c:s){
        if(c=='('){
            opbr+=1;
        }
        else if(c==')'){
            opbr-=1;
        }
        ans= max(ans,opbr);
     }
     return ans;
    }
};