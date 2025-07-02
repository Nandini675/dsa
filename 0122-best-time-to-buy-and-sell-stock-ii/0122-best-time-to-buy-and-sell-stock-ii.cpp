class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //  kisi particular din ya toh stock khrid skte ho- yni
//         Har din par do state ho sakti hain:
// Buy Allowed hai (yaani tere paas abhi koi stock nahi hai)
// Ya toh buy karein
// Ya skip karein
// Buy Not Allowed (yaani tere paas stock hai, ab tu sell kar sakta hai)
// Ya toh sell karein
// Ya skip karein
         int aheadbuy=0,aheadnotbuy=0;// opt to buy or buynot
         int currbuy,currnotbuy;
         for(int i=prices.size()-1;i>=0;i--){
             currbuy= max(-prices[i]+aheadnotbuy,0+aheadbuy);
             currnotbuy= max(prices[i]+aheadbuy,0+aheadnotbuy);
              aheadbuy= currbuy;
              aheadnotbuy=currnotbuy;

         }
         return aheadbuy;

    }
};