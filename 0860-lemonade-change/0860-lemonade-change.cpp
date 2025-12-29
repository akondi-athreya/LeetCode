class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        int n = bills.size();
        for (int i = 0 ; i < n ; i++) {
            if (bills[i] == 5) c5++;
            else if (bills[i] == 10) {
                if (c5 > 0) {
                    c5--;
                    c10++;
                } else {
                    return false;
                }
            }
            else {
                if (c10 >= 1 && c5 >= 1) {
                    c5--;
                    c10--;
                    c20++;
                }
                else if(c10 == 0 && c5 >= 3) {
                    c5-=3;
                    c20++;
                }
                else return false;
            }
        }
        return true;
    }
};


// 5,5,5,10,20
//            |

// 5  - 1
// 10 - 0
// 20 - 1