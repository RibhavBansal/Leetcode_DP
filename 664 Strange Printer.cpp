class Solution {
public:
    int solve(int i, int j, string s, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 1 + solve(i+1,j,s,dp);
        // cout << ans << endl;
        for(int k = i+1; k <= j; k++){
            if(s[i] == s[k]){
                ans = min(ans,solve(i,k-1,s,dp)+solve(k+1,j,s,dp));
            }
        }

        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int k = solve(0,s.size()-1,s,dp);
        return k;
    }
};