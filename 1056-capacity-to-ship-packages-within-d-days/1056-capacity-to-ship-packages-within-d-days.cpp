class Solution {
public:
int nofdays(vector<int>& weights, int cap){
    int nfd=1;
   int  load=0;
    int n= weights.size();
    for(int i=0;i<n;i++){
        if( load+weights[i]>cap){
            nfd+=1;
            load=weights[i];
        }
     else{
        load+= weights[i];
     }
    }
    return nfd;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int s= *max_element(weights.begin(),weights.end());
        int e= accumulate(weights.begin(),weights.end(),0);
        
        int mid= s+(e-s)/2;
        while(s<=e){
 if( nofdays(weights,mid)<= days){
    e= mid-1;
 }
 else{s= mid+1;}
 mid= s+(e-s)/2;
        }
       return s; 
    }
};