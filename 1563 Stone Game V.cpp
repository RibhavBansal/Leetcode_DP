class Solution {
public:
    vector<int>suf;
    vector<vector<int>>dp;
    int f(int i, int j, vector<int>&a){
        if(i >= j) return 0;
        if(j-i == 1){
            return min(a[i],a[j]);
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int cnt = 0, sm1 = 0, sm2 = 0;
        for(int k = i; k < j; k++){
            sm1 += a[k];
            sm2 = suf[k+1] - suf[j+1];

            if(sm1 < sm2){
                // cout << i << " " << j << " " << cnt << endl;
                cnt = max(cnt,sm1 + f(i,k,a));
            }
            else if(sm1 > sm2){
                cnt = max(cnt,sm2 + f(k+1,j,a));
            }
            else{
                cnt = max(cnt,sm2 + f(k+1,j,a));
                cnt = max(cnt,sm1 + f(i,k,a));
            }
        }

        return dp[i][j] = cnt;
    }

    int stoneGameV(vector<int>& a) {
        dp = vector(a.size()+1,vector(a.size()+1,-1));
        suf = vector(a.size()+1,0);
        suf[a.size()-1] = a[a.size()-1];
        for(int i = a.size()-2; i >= 0; i--){
            suf[i] = suf[i+1] + a[i];
        }

        // for(auto it : suf){
        //     cout << it << " ";
        // }
        // cout << endl;

        int k = f(0,a.size()-1,a);
        return k;
    }
};