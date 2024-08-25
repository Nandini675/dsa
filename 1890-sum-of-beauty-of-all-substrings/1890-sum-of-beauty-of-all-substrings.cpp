class Solution {
public:
    int beautySum(string s) {
       int sum=0;
       int n= s.length();
       for(int i=0;i<n;i++) {
       vector<int>freq(26,0);
int maxi= 0;
          for(int j=i;j<n;j++){
int ind= s[j]-'a';
freq[ind]++;
maxi= max(maxi, freq[ind]);
        int mini= INT_MAX;
        for(int k=0;k<26;k++)  {
            if(freq[k]>0)
            mini= min(mini,freq[k]);
        }  
           
           sum+= maxi- mini;
           }
           
       
       }
       return sum;
    }
};