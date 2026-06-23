class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        int carry = 0;
        int n = num1.size() , m = num2.size();
        int i = 0;
        string ans = "";
        while (i < n && i < m) {
            int a = (num1[i] - '0');
            int b = (num2[i] - '0');
            int c = a+b+carry;
            carry = 0;
            if (c >= 10) {
                carry = 1;
            }
            ans += to_string(c % 10);
            i++;
        }
        
        while (i < n) {
            int a = (num1[i] - '0');
            int b = a+carry;
            carry = 0;
            if (b >= 10) {
                carry = 1;
            }
            ans += to_string(b % 10);
            i++;
        }
        
        while (i < m) {
            int a = (num2[i] - '0');
            int b = a+carry;
            carry = 0;
            if (b >= 10) {
                carry = 1;
            }
            ans += to_string(b % 10);
            i++;
        }
        
        if (carry) {
            ans += to_string(carry);
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};