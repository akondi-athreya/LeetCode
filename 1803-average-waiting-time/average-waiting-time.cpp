class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double total = 0;
        int curr = 0;
        for(auto &i : customers){
            int at = i[0];
            int ct = i[1];
            if(curr < at){
                curr = at;
            }
            int wt = curr + ct - at;
            total += wt;
            curr += ct;

        }
        return total/n;
    }
};