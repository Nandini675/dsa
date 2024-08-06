class Solution {
public:
bool possible(int day,vector<int>& bloomDay,int m,int k ){
    int cnt=0;
    int nbq=0;
     int n= bloomDay.size();
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            nbq+= (cnt/k);
            cnt=0;
        }
    }
    nbq+=(cnt/k);
    return (nbq>=m);
  

}


    int minDays(vector<int>& bloomDay, int m, int k) {
          int n= bloomDay.size();
          long long val = m*1ll*k*1ll;
          if(val>n) return -1;
          int mini=INT_MAX, maxi=INT_MIN;
          for(int i=0;i<n;i++){
            maxi= max(bloomDay[i],maxi);
            mini= min(bloomDay[i],mini);

          }
          int s=mini,e=maxi;
        int mid= s+(e-s)/2;
        while(s<=e){
            if( possible(mid,bloomDay,m,k)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
           mid= s+(e-s)/2; 
        }

return s;

    }
};