class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         bool intervalInserted = false;
        bool processingNewInterval = false;
        vector<vector<int>> res;

        for (auto &pr: intervals)
        {
            if (processingNewInterval)
            {
                if (pr[0] <= res.back()[1])
                    res[ res.size() - 1 ][1] = max(res.back()[1], pr[1]);
                else
                {
                    res.push_back(pr);
                    processingNewInterval = false;
                }

                continue;
            }

            if (pr[1] >= newInterval[0])
            {
                if (pr[0] > newInterval[1])
                {
                    if (!intervalInserted)
                    {
                        intervalInserted = true;
                        res.push_back(newInterval);
                    }
                }
                else
                {
                    intervalInserted = true;
                    res.push_back({min(pr[0], newInterval[0]), max(pr[1], newInterval[1])});
                    processingNewInterval = true;
                    continue;
                }
            }

            res.push_back(pr);
        }

        if (intervals.empty() || intervals.back()[1] < newInterval[0])
            res.push_back(newInterval);
        
        return res;

    }
};