class Solution {
public:
    int solve(int i, int j, string &a, string &b, vector<vector<long long int>>&dp){
        if(j >= b.size()){
            return 1;
        }
        
        if(i >= a.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int a1 = 0;
        if(a[i] == b[j]){
            a1 = solve(i+1,j+1,a,b,dp);
        }

        int a2 = solve(i+1,j,a,b,dp);

        return dp[i][j] = a1+a2;
    } 

    int numDistinct(string a, string b) {
        int n = a.size();
        int m = b.size();
        if(!n || !m)
        return 0;
        
        vector<vector<long long int>>dp(n,vector<long long int>(m,-1));
        return solve(0,0,a,b,dp);
    }
};

// *********** TABULATION **************

// class Solution {
// public:
//     int prime = 1e9+7;
//     int numDistinct(string a, string b) {
//         int n = a.size();
//         int m = b.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
//         for(int i=0;i<n+1;i++){
//             dp[i][0]=1;
//         }
//         for(int i=1;i<m+1;i++){
//             dp[0][i]=0;
//         }

//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<m+1;j++){

//                 if(a[i-1]==b[j-1])
//                     dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
//                 else
//                     dp[i][j] = dp[i-1][j]%prime;
//             }
//         }


//         return dp[n][m];
//     }
// };
