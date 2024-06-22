class Solution {
public:
    vector<vector<int>>dp;
    int f(vector<int>&v,vector<int>&v2,int i,bool swap){
        if(i>=v.size())return 0;
        if(dp[i][swap]!=-1)return dp[i][swap];
        int val = 1e9;
        if(swap){
            if(v[i]>v2[i-1]&&v2[i]>v[i-1]){
                val = min(val,f(v,v2,i+1,0));
            }
            if(v[i]>v[i-1]&&v2[i]>v2[i-1]){
                val = min(val,1+f(v,v2,i+1,1));
            }
        }
        else{
            if(v[i]>v[i-1]&&v2[i]>v2[i-1]){
                val = min(val,f(v,v2,i+1,0));
            }
            if(v[i]>v2[i-1]&&v2[i]>v[i-1]){
                val = min(val,1+f(v,v2,i+1,1));
            }
        }
        return dp[i][swap] =  val;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size(),vector<int>(2,-1));
        return min(f(nums1,nums2,1,0),1+f(nums1,nums2,1,1));
    }
};

      