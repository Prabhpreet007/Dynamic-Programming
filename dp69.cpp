// 343. Integer Break
// T.C = O(n²)

class Solution {
public:

    long long findAns(int n,bool check,vector<vector<int>>&dp){
        if(n==1 || n==0){
            return 1;
        }

        if(dp[n][check]!=-1){
            return dp[n][check];
        }

        long long ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(check==false && i==n)break;
            long long curr=findAns(n-i,true,dp)*i;
            ans=max(ans,curr);
        }
        return dp[n][check] = ans;

    }

    int integerBreak(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return int(findAns(n,false,dp));
    }
};