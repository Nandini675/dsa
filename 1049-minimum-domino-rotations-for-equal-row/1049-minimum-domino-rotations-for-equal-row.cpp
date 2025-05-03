class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
vector<int>cnttop (7,0);
vector<int>cntbot (7,0);
vector<int>cntsame (7,0);
 for( int i=0;i<tops.size();i++){
    cnttop[tops[i]]++;
    cntbot[bottoms[i]]++;
    
if(tops[i]==bottoms[i]) cntsame[tops[i]]++;
 }
  for( int i=1;i<=6;i++){
    if((cnttop[i]+(cntbot[i]-cntsame[i]))== tops.size())
    return min( cnttop[i]-cntsame[i], cntbot[i]-cntsame[i]);
  }
 return -1;
    }
};