class Solution {
public:
    string minWindow(string s, string t) {
        int m= t.length();
         int n= s.length();
       int  s_idx=-1;
         int minlen= INT_MAX; 
         int cnt=0;// kep a track ki t ke kitne chracters s ki substring mai aa chuke hai
          int l=0, r=0;
         int hash[256]={0};
          for(int i=0;i<m;i++) hash[t[i]]++;
          while(r<n){
             if(hash[s[r]]>0)  {cnt++; }
             hash[s[r]]--;
              while(cnt==m){
                 if(minlen> r-l+1){
                    minlen= r-l+1;
                    s_idx=l;
                 }
                  hash[s[l]]++;
                   if(hash[s[l]]>0) cnt--;
                  l++;
              }
             r++;  
          }
           return s_idx==-1?  "": s.substr(s_idx, minlen);
    }
};