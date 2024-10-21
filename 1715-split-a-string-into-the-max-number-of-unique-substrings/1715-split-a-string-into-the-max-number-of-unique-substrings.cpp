class Solution {
public:
    int maxUniqueSplit(string s) {
        int result = 0;
        unordered_set<string> memo; // to store unique substrings
        
        function<void(int, string)> backtrack = [&](int i, string curr) {
            if (i == s.length()) {
                if (!curr.empty() && memo.find(curr) == memo.end()) {
                    result = max((int)memo.size() + 1, result);
                }
                return;
            }

            curr += s[i];
            
            // Split here if `curr` is unique
            if (memo.find(curr) == memo.end()) {
                memo.insert(curr);
                backtrack(i + 1, "");
                memo.erase(curr);
            }
            
            // Continue without splitting
            backtrack(i + 1, curr);
        };
        
        backtrack(0, "");
        return result;
    }
};