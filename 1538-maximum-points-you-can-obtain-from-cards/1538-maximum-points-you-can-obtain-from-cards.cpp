class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int ls=0,rs=0;
      int maxi=0;  
      for(int i=0;i<k;i++)  ls+=cardPoints[i];// phle leftsde se k elemnts utha liye
      maxi=ls;
     int  r=cardPoints.size()-1;
       for(int i= k-1;i>=0;i--){
        // ab left side se ek -ek ele rome krnge aur ryt se ek ek pick krenge
         ls -= cardPoints[i];
         rs+= cardPoints[r];
         r--;
          maxi=max(maxi, ls+rs);
       }
return maxi;
    }
};