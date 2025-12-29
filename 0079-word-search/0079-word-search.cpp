class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool fun(vector<vector<char>>& board, int m, int n, int i, int j, int idx, string word) {
        if (idx == word.length()) return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '@') return false;

        if (board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '@';

        for (auto &it : dir) {
            int ni = i + it[0];
            int nj = j + it[1];

            if (fun(board, m, n, ni, nj, idx+1, word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (board[i][j] == word[0] && fun(board, m, n, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};