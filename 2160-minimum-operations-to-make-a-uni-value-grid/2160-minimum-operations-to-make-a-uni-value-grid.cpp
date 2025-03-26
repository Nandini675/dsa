class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (const auto& row : grid) {
            for (int num : row) {
                arr.push_back(num);
            }
        }
        
        sort(arr.begin(), arr.end());
        int mid = arr[arr.size() / 2];
        int operations = 0;
        
        for (int num : arr) {
            if (abs(num - mid) % x != 0) return -1;
            operations += abs(num - mid) / x;
        }
        
        return operations;
    }
};