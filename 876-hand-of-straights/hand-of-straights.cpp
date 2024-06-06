class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false;
        unordered_map<int , int> mp;
        for(int card : hand) mp[card]++;
        for(int card : hand){
            int sc = card;
            while(mp[sc-1]){
                sc--;
            }
            while(sc <= card){
                while(mp[sc]){
                    for(int i=sc ; i<sc+groupSize ; i++){
                        if(!mp[i]) return false;
                        mp[i]--;
                    }
                }
                sc++;
            }
        }
        return true;
    }
};