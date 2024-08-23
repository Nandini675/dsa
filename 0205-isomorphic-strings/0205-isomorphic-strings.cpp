class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int l1 =s.size();
       int l2= t.size();
    if(l1!=l2) return false;
    unordered_map<char,vector<int>>m1;
    unordered_map<char,vector<int>>m2;
    for(int i=0;i<l1;i++){
        
        m1[s[i]].push_back(i);
    }
    for(int i=0;i<l2;i++){
    
        m2[t[i]].push_back(i);
    }
    
 for(int i=0;i<l1;i++){
    if(m1[ s[i]]!= m2[t[i]])
    return false;
 }
 return true;
    }
};