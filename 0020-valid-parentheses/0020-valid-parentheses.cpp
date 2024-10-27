class Solution {
public:
    bool isValid(string s) {
        stack<char> ch;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                ch.push(c);
            } else {
                if (ch.empty() || (c == ')' && ch.top() != '(') || (c == ']' && ch.top() != '[') || (c == '}' && ch.top() != '{')) {
                    return false;
                }
                ch.pop();
            }
        }
        return ch.empty();
    }
};
