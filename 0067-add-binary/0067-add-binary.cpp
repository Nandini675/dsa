class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        char carry = '0';
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            if (carry == '1') {
                if(a[i] == '0') {
                    a[i] = '1';
                    carry = '0';
                }
                else{
                    a[i] = '0';
                    carry = '1';
                }
            }
            if (a[i] == '1' && b[j] == '0')
                ans = "1" + ans;
            else if (a[i] == '0' && b[j] == '1')
                ans = "1" + ans;
            else if (a[i] == '0' && b[j] == '0')
                ans = "0" + ans;
            else {
                carry = '1';
                ans = "0" + ans;
            }
            i--;
            j--;
        }
        while( i >= 0) {
            if (carry == '1') {
                if(a[i] == '0') {
                    a[i] = '1';
                    carry = '0';
                }
                else{
                    a[i] = '0';
                    carry = '1';
                }
            }
            if (a[i] == '1')
                ans = "1" + ans;
            else if (a[i] == '0')
                ans = "0" + ans;
            else {
                carry = '1';
                ans = "0" + ans;
            }
            i--;
        }
        while(j >= 0) {
            if (carry == '1') {
                if(b[j] == '0') {
                    b[j] = '1';
                    carry = '0';
                }
                else{
                    b[j] = '0';
                    carry = '1';
                }
            }
            if (b[j] == '1')
                ans = "1" + ans;
            else if (b[j] == '0')
                ans = "0" + ans;
            else {
                carry = '1';
                ans = "0" + ans;
            }
            j--;
        }
        if(carry == '1')
            ans = "1" + ans;
        return ans;
    }
};