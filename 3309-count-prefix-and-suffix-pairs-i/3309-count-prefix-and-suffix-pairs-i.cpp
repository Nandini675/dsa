class Solution {
public:
bool helper( string str1, string str2){
     int n1= str1.length();
     int n2= str2.length();
     if (n1>n2 ) return false;
      return ( str2.substr(0,n1)== str1 && str2.substr(n2-n1)== str1);
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int n= words.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 if(helper(words[i], words[j])){
                    cnt++;
                 }
            }
        }
        return cnt;
    }
};