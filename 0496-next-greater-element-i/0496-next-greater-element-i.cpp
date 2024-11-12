class Solution {
public:
 vector<int> greaterele(vector<int>nums2){
    vector<int>ans(nums2.size()) ;
        stack<int>s;
        s.push(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.top()!=-1&& nums2[i]>s.top()){
s.pop();



            }
            ans[i]=s.top();
            s.push(nums2[i]);
        }
        return ans;
 }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int>greaterelarray(nums2.size());
      vector<int>an;
      greaterelarray= greaterele(nums2);
      for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums2[j]==nums1[i]){
            
 an.push_back(greaterelarray[j]);
               
                }
            }
           
        }
 return an;
      }

    
};