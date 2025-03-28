class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<int>v1=points[0];
        int ok=1;
        for(int i=1;i<points.size();i++){
            if(v1[1]>=points[i][0]){
                v1[0]=max(v1[0],points[i][0]);
                v1[1]=min(v1[1],points[i][1]);
            }
            else{
                 v1[0]=points[i][0];
                v1[1]=points[i][1];
                ok++;
            }
        }
        return ok;
    }
};