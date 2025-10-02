class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
     int n=  numBottles;

     int m =numExchange;
      int drunkbot=n, emptybot=n;
       while( emptybot>= m){
 emptybot-= m;
 m++;
  drunkbot++;
  emptybot++;
       }
       return drunkbot;

    }
};