class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
         int n= arr.size();

if( n==0) return 0;
int cnk=0; int maxi= 0;
for(int i=0;i<n;i++){
    maxi= max(maxi, arr[i]);
    if(maxi==i)
    cnk++;
}
return cnk;
    }
};