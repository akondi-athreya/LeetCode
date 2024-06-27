class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x = edges[0][0];
        int y = edges[0][1];
        int xcnt=1 , ycnt=1;
        for(int i=1 ; i<edges.size() ; i++){
            if(edges[i][0] == x || edges[i][1] == x) xcnt++;
            else if(edges[i][1] == y || edges[i][1] == y) ycnt++;
        }
        if(xcnt>ycnt) return x;
        else return y;
    }
};