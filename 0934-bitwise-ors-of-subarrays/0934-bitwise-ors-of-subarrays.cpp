class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev, curr;

        for (int x : arr) {
            curr = {x};  // start new subarray with current element

            for (int y : prev) {
                curr.insert(x | y);  // extend previous subarrays with current element
            }

            prev = curr;
            result.insert(curr.begin(), curr.end()); // add all to result
        }

        return result.size();
    }
};
