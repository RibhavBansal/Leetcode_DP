class Solution {
public:
    int helper(vector<int>& piles, vector<int>& dp, const vector<int>& suffixSum, int i) {
        if (i == piles.size()) return 0; 
        if (dp[i] != INT_MIN) return dp[i];
        int result = INT_MIN;
        for (int x = 1; x <= 3; ++x) {
            if(i+x > piles.size()) break;
            result = max(result, suffixSum[i] - helper(piles, dp, suffixSum, i + x));
        }
        dp[i] = result;
        return result;
    }

    string stoneGameIII(vector<int>& piles) {
        if (piles.empty()) return 0;
        vector<int> dp(piles.size(),INT_MIN);
        vector<int> suffixSum(piles.size());
        suffixSum[suffixSum.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; --i) suffixSum[i] = piles[i] + suffixSum[i + 1];
        int k = helper(piles, dp, suffixSum, 0);
        int l = suffixSum[0] - k;

        cout << k << " " << l << endl;
        return k == l ? "Tie" : k < l ? "Bob" : "Alice";
    }
};
