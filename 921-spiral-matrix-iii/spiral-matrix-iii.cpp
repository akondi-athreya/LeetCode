class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dirac = {
            {0,1}, //EAST
            {1,0}, //SOUTH
            {0,-1}, //WEST
            {-1,0} //NORTH
        };

        int dir = 0;
        int steps = 0;

        vector<vector<int>> res;
        res.push_back({rStart,cStart});
        while(res.size() < rows*cols){
            if(dir==0 || dir==2) steps++;

            for(int i=0 ; i<steps ; i++){
                rStart += dirac[dir][0];
                cStart += dirac[dir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    res.push_back({rStart,cStart});
                }
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};