class Solution {
public:
    // unordered_map<char, int> mp = {
    //     'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000
    // };
    // bool isValid(string s, ) {
    //     int val1 = mp[s[0]];
    //     int val2 = mp[s[1]];

    //     return ((val2-val1) != val1);
    // }
    string intToRoman(int num) {
        string ans = "";

        // thousands
        int cntM = num/1000;
        if (cntM > 0) {
            ans += string(cntM, 'M');
        }
        num = num%1000;

        // hundreds
        int cntH = num/100;
        if (cntH == 9) ans+="CM";
        else if(cntH >= 5) {
            cntH -= 5;
            ans += 'D';
            ans += string(cntH, 'C');
        }
        else {
            if (cntH == 4) {
                ans += "CD";
            }
            else ans += string(cntH, 'C');
        }
        num = num%100;

        // tens
        int cntT = num/10;
        cout << ans << "\n";
        if (cntT == 9) ans+= "XC";
        else if(cntT >= 5) {
            cntT -= 5;
            ans += 'L';
            ans += string(cntT, 'X');
        }
        else {
            if (cntT == 4) {
                ans += "XL";
            }
            else ans += string(cntT, 'X');
        }
        num = num%10;

        // ones
        if (num == 9) ans += "IX";
        else if(num >= 5) {
            num -= 5;
            ans += 'V';
            ans += string(num, 'I');
        }
        else {
            if (num == 4) {
                ans += "IV";
            }
            else ans += string(num, 'I');
        }

        return ans;
    }
};