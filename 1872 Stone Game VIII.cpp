class Solution {
public:
    vector<int>pref;
    vector<int>dp;
    int f(int i, int n, vector<int>&a){
        if(i == n-1) return pref[i];
        if(dp[i] != INT_MIN)
            return dp[i];
        
        int cnt = f(i+1,n,a);
        cnt = max(cnt,pref[i] - f(i+1,n,a));

        return dp[i] = cnt;
    }

    int stoneGameVIII(vector<int>& a) {
        pref = vector(a.size()+1,0);
        dp = vector(a.size()+1,INT_MIN);
        pref[0] = a[0];
        for(int i = 1; i < a.size(); i++) pref[i] = pref[i-1] + a[i];
        int k = f(1,a.size(),a);
        return k;
    }
};