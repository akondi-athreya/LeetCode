class Solution {
public:
    void rev(string &s) {
        int start = 0, end = s.size()-1;
        while(start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};

        string copy = s;
        rev(s);
        int result = 0;
        int prev = 0;
        for(int i = 0 ; i < n ; i++) {
            int answer = mp[s[i]];

            if(prev > answer) {
                result = result - answer;
                prev = mp[s[i]];
                continue;
            }
            prev = mp[s[i]];
            result += answer;
        }
        return result;
    }
};