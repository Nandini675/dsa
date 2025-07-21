class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> ans;
         int n= nums.size();
         deque<int>dq;// yha idx hi rkhenge
          for(int i=0;i<n;i++){
             while(!dq.empty()&& dq.front()==i-k)// froont pr sbse oldest our max elemnt rkha hua hai toh index wjicj exceed the curr window size == i-k eg i=3 , 3-3=0 yni 0 idx would just exceed the winow size therefor usko pop krdenge
             dq.pop_front();
              while(!dq.empty()&& nums[dq.back()]<nums[i])// agr last elemt mere incoming ele se chota hai toh usko q mai rkhne ka kkoi faeda nhi kuki vo kbhi bhi max nhi bn skta
              //ab window mai
              dq.pop_back();
               dq.push_back(i) ;// yeh sb condotion cjeck krne ke baa queue mai piche se elemt daal do
               if(i>=k-1)// agr k se bada size ka idx hai mat atelast k size ki window toh bna li
               ans.push_back(nums[dq.front()]);


          }
          return ans;
    }
};