class Solution {
public:
    int n;
    int MOD = 1e9+7;
    vector<vector<pair<int, int>>> dp;

    int getInt(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string>& board) {
        return i>=0 && i<n && j>=0 && j<n && board[i][j] != 'X';
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        dp.assign(n, vector<pair<int, int>>(n, {0, 0}));

        dp[0][0] = {0, 1};

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (board[i][j] == 'E') continue;
                if (board[i][j] == 'X') continue;

                int upScore = 0,   upPaths = 0;
                int leftScore = 0, leftPaths = 0;
                int diagScore = 0, diagPaths = 0;
                char ch = board[i][j];

                if (isValid(i - 1, j, board)) {
                    auto [score, paths] = dp[i - 1][j];
                    upScore = score;
                    upPaths = paths;
                    if (upPaths > 0)
                        upScore += getInt(ch);
                }
                if (isValid(i, j - 1, board)) {
                    auto [score, paths] = dp[i][j - 1];
                    leftScore = score;
                    leftPaths = paths;
                    if (leftPaths > 0)
                        leftScore += getInt(ch);
                }
                if (isValid(i - 1, j - 1, board)) {
                    auto [score, paths] = dp[i - 1][j - 1];
                    diagScore = score;
                    diagPaths = paths;
                    if (diagPaths > 0)
                        diagScore += getInt(ch);
                }

                int bestScore, bestPaths;
                if (upScore == leftScore && leftScore == diagScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths + diagPaths;
                } else if (upScore == leftScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths;
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                } else if (leftScore == diagScore) {
                    bestScore = leftScore;
                    bestPaths = leftPaths + diagPaths;
                    if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                        bestScore = upScore; bestPaths = upPaths;
                    }
                } else {
                    bestScore = upScore; bestPaths = upPaths;
                    if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                        bestScore = leftScore; bestPaths = leftPaths;
                    }
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                }

                dp[i][j] = {bestScore, bestPaths % MOD};
            }
        }
        auto res = dp[n-1][n-1];
        return {res.first, res.second};
    }
};