class Solution {
public:
    int countGoodNumbers(long long n) {
         return (int) ((findpow(5,(n+1)/2) *findpow(4,n/2) ) % mod);
    }

    const int mod=1e9 + 7;
     long long  findpow(long long  a, long long b){
          if(b==0) return 1;
           long long half= findpow(a,b/2);
           long long  res= (half* half) % mod;
            if( b%2 ==1){
                 res= (res*a)% mod;
            }
return res;
     }
};