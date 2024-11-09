class Solution {
public:
 vector<int>nextsmallerelement(vector<int> arr, int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i= n-1;i>=0;i--){
        int curr= arr[i];
        while(s.top()!=-1 && arr[s.top()]>= curr){
            s.pop();
        }
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
 }
 vector<int>prevsmallerelement(vector<int> arr, int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i= 0;i<n;i++){
        int curr= arr[i];
        while(s.top()!=-1 && arr[s.top()]>= curr){
            s.pop();
        }
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
 }

    int largestRectangleArea(vector<int>& heights) {
      int n= heights.size();
      vector<int> next;
      vector<int> prev;

        next= nextsmallerelement(heights, n);
            prev= prevsmallerelement(heights,n);
            int area = INT_MIN;
            for(int i=0;i<n;i++){
                 int l= heights[i];
                 if(next[i]==-1){
                    next[i]= n;
                 }
                 int b= next[i]- prev[i]-1;
                 int nextarea= l*b;
                 area= max(nextarea, area);
            }
return area;
    }
};