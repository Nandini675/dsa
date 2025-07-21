class Solution {
public:
    string makeFancyString(string s) {
        
         // mujhe hr baar pev 2 charcter ko check krna hai ki khi vo imcoming charater hai usse same toh nhi hai agr esa hai toh skip taht incomong character move forward
         string res="";
          for( auto c:s){
             if(res.size()>=2&& res.back()==c&& res[res.size()-2]==c)
             continue;
             res.push_back(c);
            }
return res;
    }
};