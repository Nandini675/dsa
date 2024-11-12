class Solution {
public:
    int binSearch(int num, vector<vector<int>>& items) {
        int low = 0, high = items.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (items[mid][0] <= num) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        int maxBeauty = 0;
        for (int i = 0; i < items.size(); ++i) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;//finding the beauty and placing them inplace without using extra memory
        }
        
        vector<int> ans;
        ans.reserve(queries.size()); 
        for (int query : queries) {
            int index = binSearch(query, items);
            if (index != -1) {
                ans.push_back(items[index][1]);
            } else {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};