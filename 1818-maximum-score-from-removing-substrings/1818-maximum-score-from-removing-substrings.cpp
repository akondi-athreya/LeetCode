class Solution {
public:
    pair<string, int> removeSubstr(string& s, string& matchStr) {
        stack<char> st;
        int count = 0;
        for (char ch : s) {
            if (!st.empty() && st.top() == matchStr[0] && ch == matchStr[1]) {
                st.pop();
                count++; 
            } else {
                st.push(ch);
            }
        }
        string temp;
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return {temp, count};
    }
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string first = (x > y) ? "ab" : "ba";
        string second = (x > y) ? "ba" : "ab";
        int high = max(x, y), low = min(x, y);
        
        auto [s_after_first, cnt_first] = removeSubstr(s, first);
        score += cnt_first * high;
        
        auto [s_after_second, cnt_second] = removeSubstr(s_after_first, second);
        score += cnt_second * low;
        
        return score;
    }
};