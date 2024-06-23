class Solution {
public:
    int f(int i, int j, vector<int>&a, vector<vector<int>>&dp){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1)
        return dp[i][j];

        int mx = 0;
        for(int k = i; k <= j; k++){
            mx = max(mx,a[i-1]*a[k]*a[j+1] + f(i,k-1,a,dp) +f(k+1,j,a,dp));
        }

        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& a) {
        int m = a.size();
        a.push_back(1);
        a.insert(a.begin(),1);

        // for(int i = 0; i < a.size(); i++)
        //      cout << a[i] << " ";

        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return f(1,m,a,dp);
    }
};