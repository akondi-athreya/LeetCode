class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));
        int n = players.size(), m = trainers.size();
        int j = 0;
        int cnt = 0;
        bool flag = false;
        for(int i = 0 ; i < n ; i++) {
            if(j == m) break;
            while(players[i] > trainers[j] && j < m-1) {
                j++;
            }
            if(players[i] <= trainers[j] && j < m) {
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};