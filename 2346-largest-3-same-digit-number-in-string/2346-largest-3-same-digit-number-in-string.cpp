class Solution {
public:
    string largestGoodInteger(string num) {
         string best="";
 int n= num.length();
        for(int  i=0;i+2<n;i++){
             if(num[i]== num[i+1]&& num[i+1]==num[i+2]){
                 best= max(best, num.substr(i,3));
             }
        }
        return best;
    }
};