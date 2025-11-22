// 279. Perfect Squares

// T.C = O(n · sqrt(n))

class Solution {
public:

    int findAns(int n,vector<int>&dp){
        if(n==1 || n==0)return n;
        if(dp[n]!=-1)return dp[n];

        int mini=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int curr=1+findAns(n-(i*i),dp);
            mini=min(mini,curr);
        }

        return dp[n]= mini;
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return findAns(n,dp);
    }
};