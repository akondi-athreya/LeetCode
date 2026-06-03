class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        int minLandFinish = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }

        int minWaterFinish = INT_MAX;
        for (int j = 0 ; j < m ; j++) {
            minWaterFinish = min(minWaterFinish, waterStartTime[j] + waterDuration[j]);
        }

        for (int j = 0 ; j < m ; j++) {
            int finishTime = max(minLandFinish, waterStartTime[j]) + waterDuration[j];
            ans = min(ans, finishTime);
        }

        for (int i = 0 ; i < n ; i++) {
            int finishTime = max(minWaterFinish, landStartTime[i]) + landDuration[i];
            ans = min(ans, finishTime);
        }

        return ans;
    }
};