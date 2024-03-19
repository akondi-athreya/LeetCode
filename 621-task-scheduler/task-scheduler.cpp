class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //int n=0;
        int total=tasks.size();
        unordered_map<char,int>mp;
        int max1=0;
        int maxco=0;
        for(char it:tasks){
            mp[it]++;
            if(max1<mp[it]){
                max1=mp[it];
            }
        }
        for(auto it:mp){
            if(it.second==max1){
                maxco++;
            }
        }
        return max((max1-1)*(n+1)+maxco,total);
    }
};