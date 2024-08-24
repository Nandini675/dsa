class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> count;
         for(char c:s)
         count[c]+=1;
         vector<pair<char,int>> count_vec(count.begin(),count.end());
         sort(count_vec.begin(),count_vec.end(),[](pair<char,int>& p1, pair< char,int>& p2
         ){
            return p1.second>p2.second;
         });
          string result="";
           for( pair<char,int>p: count_vec){
            for(int i=0;i<p.second;i++)
            result+= p.first;
           }
           return result;

    }
};