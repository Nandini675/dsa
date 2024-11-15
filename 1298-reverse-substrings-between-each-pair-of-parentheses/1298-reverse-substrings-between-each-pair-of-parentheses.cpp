
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch == ')') {
                // Collect characters until we reach '('
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                
                // Pop the opening parenthesis '('
                if (!st.empty()) st.pop();
                
                // Push the reversed substring back onto the stack
                for (char c : temp) {
                    st.push(c);
                }
            } else {
                // Push the current character to the stack
                st.push(ch);
            }
        }
        
        // Construct the final answer by popping from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Reverse the final string to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

