class Solution {
public:
  long long createpalind(long long  num, bool odd){
     long long x= num;
     if(odd) x= x/10;
     while(x>0){
        num= num*10+ x%10;
        x/=10;
     }
     return num;
 }
  bool ispalindrome(long long num, int base){
 vector<int>dig;
 while(num>0){
    dig.push_back(num%base);
    num/=base;
 }
 int i=0,j= dig.size()-1;
 while(i<j){
    if(dig[i++]!= dig[j--]) return false;
 }
return true;
  }
    long long kMirror(int k, int n) {
         long long sum=0;
         for( long long i= 1;n>0;i*=10 )// yeh loop batayega ki kitni len ka no banna hai phle
         // i se i*10 ke beech ke no lena hai
         {

         for( long long j=i;n>0&& j<i*10;j++){
long long p= createpalind(j,true);     // creating odd legth pallindrome no

 if(ispalindrome(p,k)){
    sum+=p;
    n--;
 }
         }
                for( long long j=i;n>0&& j<i*10;j++){
long long p= createpalind(j,false);     // creating even legth pallindrome no

 if(ispalindrome(p,k)){
    sum+=p;
    n--;
 }
         }

         }
         return sum;
    }
};