class Solution {
public:
    int characterReplacement(string s, int k) {
         int l=0;int r=0;
         int maxfreq=0; int maxi=0;
        int hash[26]={0};
         while(r< s.length()){
             hash[s[r]-'A']++;
              maxfreq= max( maxfreq,hash[s[r]-'A']);
               if(( (r-l+1)- maxfreq )>k){
                 hash[s[l]-'A']--; 
                 l++;}
 else maxi= max(maxi, r-l+1);
 r++;
         }
         return maxi;
    }
};