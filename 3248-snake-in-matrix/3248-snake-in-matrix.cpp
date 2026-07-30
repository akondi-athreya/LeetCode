class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int r = 0, c = 0;
        for (string& s : commands) {
            if (s == "UP") r--;
            else if (s == "DOWN") r++;
            else if (s == "LEFT") c--;
            else if (s == "RIGHT") c++;
        }
        return (r * n) + c;
    }
};