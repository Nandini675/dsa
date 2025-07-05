class Solution {
public:
//n=4, k=17
    string getPermutation(int n, int k) {
        int fact=1;// factorial decide krnge ki kitne blocks banne hai
        vector<int>nu;//num will store numbers from 1ton
        for( int i=1;i<n;i++){
             fact=fact*i;// calculating factorial
             // initialyy 6 blocks bne i.e(n-1)!
             nu.push_back(i);
        }
        nu.push_back(n);
         string ans="";
         k= k-1;// bcoz of 0 based indexing
         while(true){
            // idx pr phle konsa ele aayega = k/no of block
             ans= ans+ to_string(nu[k/fact]);
            //ab vctor mai se vo elemt delete krdenge
            nu.erase(nu.begin()+k/fact);
            if(nu.size()==0)// agr koi bhi elem nhi bchtajust come out of the loop
            break;
             // ab selected set mai konse no pr pda hoga mera desied permutation
             k= k%fact;
             //ab block ka size bhi kam ho jayega
             fact=fact/nu.size();
         }
         return ans;
    }
};
// t.c:0(n^2) while loop tab tak chalega jab tak n khali nhi hojata  aur and erse operation 0(n)
// kuki index search krke element delte kr rha hai
