class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> res(26 , INT_MAX);
        vector<string> result;
        for(auto s : words){
            vector<int> cnt(26,0);
            for(auto ch : s) cnt[ch-'a']++;
            for(auto i=0 ; i<26 ; i++) res[i] = min(res[i],cnt[i]);
        }
        for(auto i=0 ; i<26 ; i++){
            for(auto j=0 ; j<res[i] ; j++){
                result.emplace_back(string(1,i+'a'));
            }
        }
        return result;
    }
};