class Solution {
public:
    int solve(int i, int b, int k, vector<int>&a, vector<vector<vector<int>>>&dp){
        if(i == a.size() || k == 0){
            return 0;
        }

        if(dp[i][b][k] != -1){
            return dp[i][b][k];
        }

        if(b){
            return dp[i][b][k] = max(-a[i] + solve(i+1,0,k,a,dp), solve(i+1,1,k,a,dp));
        } else{
            return dp[i][b][k] = max(a[i] + solve(i+1,1,k-1,a,dp),solve(i+1,0,k,a,dp));
        }
        return 0;
    }

    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,a,dp);
    }
};