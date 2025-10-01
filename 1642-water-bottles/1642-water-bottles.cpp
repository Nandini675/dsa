class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n= numExchange;
        int m= numBottles;
      int drinkedbot=0,eb=0;
       while(m>0){
         drinkedbot+= m;
         eb+= m;
          m=eb/n;
          eb= eb%n;
       }

         return drinkedbot;
    }
};