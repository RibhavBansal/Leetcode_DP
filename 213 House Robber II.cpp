class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>&vis, vector<int>&dp)
    {
        if(i >= n)return 0;

        if(dp[i] != -1)
        return dp[i];

        if(i == n-1){
            if(vis[0] != 0){
                // if(nums[i] > nums[0])
                // return nums[i]-nums[0];
                
                return 0;
            }
            return nums[i];
        }

        int k1 = solve(nums,i+1,n,vis,dp);
        vis[i] = 1;
        int k2 = nums[i]+solve(nums,i+2,n,vis,dp);
        
        return dp[i] = max(k1,k2);
    }
    int solve(vector<int> &nums, int i, int n, bool first, vector<int>&dp)
    {
        if(i>=n)
            return 0;
            
        if(i==(n-1))
        {
            if(first==true)
            {
                return dp[i] = 0;
            }
            else
            {
                return dp[i] = nums[i];
            }
        }
		int a = nums[i]+solve(nums, i+2, n, first, dp);
        int b = solve(nums, i+1, n, first, dp);
        return dp[i] = max(a, b);
    }

    int rob(vector<int>& a) {
        int n = a.size();
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);

        dp1[n-1] = a[n-1];
        for(int i = n-2; i > 0; i--){
            dp1[i] = dp1[i+1];
            if(i < n-2)
                dp1[i] = max(dp1[i],a[i] + dp1[i+2]);
            else
                dp1[i] = max(dp1[i],a[i]);
        }
        if(n > 1)
        dp1[0] = dp1[1];

        dp2[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            dp2[i] = dp2[i+1];
            if(i < n-2)
                dp2[i] = max(dp2[i],a[i] + dp2[i+2]);
            else
                dp2[i] = max(dp2[i],a[i]);
        }
        
        return max(dp1[0],dp2[0]);
    }

    // int rob(vector<int>& nums) {
    //     vector<int>vis(nums.size(),0);
    //     vector<int>dp(nums.size(),-1);
    //     // int k1 = solve(nums,2,nums.size(),true,dp);
    //     // int k2 = solve(nums,1,nums.size(),false,dp);
    //     // dp[0] = max(k1+nums[0],k2);
        
    //     int k = solve(nums,0,nums.size(),vis,dp);

    //     for(auto it : dp)
    //     cout << it << " ";
    //     cout << endl;

    //     // return max(k1+nums[0],k2);
    //     return k;
    // }
};
