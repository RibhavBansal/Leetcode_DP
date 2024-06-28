class Solution {
public:
    vector<int> dp;

    bool solve(int n) {
        if (dp[n] != -1) 
            return dp[n];

        for (int i = 1; i * i <= n; ++i) {
            if (!solve(n - i * i)) {
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return false;
    }

    bool winnerSquareGame(int n) {
        dp = vector<int>(n + 1, -1);
        dp[0] = 0; // Base case: no stones means the current player loses
        return solve(n);
    }
};
