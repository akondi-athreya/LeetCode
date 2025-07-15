class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < word.size() ; i++) {
            char c = word[i];
            if(c == '@' || c == '#' || c == '$') return false;

            else if((int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122)) {
                if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                    c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt1++;
                
                else cnt2++;
            }
        }
        if(cnt1 > 0 && cnt2 > 0) return true;
        return false;
    }
};