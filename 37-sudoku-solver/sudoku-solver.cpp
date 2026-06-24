class Solution {
public:
    bool fun(vector<vector<char>>& v) {
        for (int i = 0 ; i < v.size() ; i++) {
            for (int j = 0 ; j < v[0].size() ; j++) {
                if (v[i][j] == '.') {
                    for (char c = '1' ; c <= '9' ; c++) {
                        if (canWePut(v, i, j, c)) {
                            v[i][j] = c;

                            if (fun(v) == true) return true;
                            else v[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool canWePut(vector<vector<char>>& v, int row, int col, char ch) {
        for (int i = 0 ; i < 9 ; i++) {
            if (v[i][col] == ch) return false;

            if (v[row][i] == ch) return false;

            if (v[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(board);
    }
};