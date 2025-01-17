class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n= derived.size();
        int x= derived[0];
         for(int i=1;i< n;i++){
              x^= derived[i];
         }
         return (x==0);
    }
};