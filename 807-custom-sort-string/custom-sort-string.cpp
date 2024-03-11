class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        string str = "";
        for(auto it : s) mp[it]++;
        for(auto it : order){
            if(mp.find(it) != mp.end()){
                auto temp = mp.find(it);
                int cnt = temp->second;
                string s1(cnt,it);
                str += s1;
                mp.erase(it);
            }
        }
        for(auto it : mp){
            string s2(it.second , it.first);
            str+=s2;
        }
        return str;
    }
};