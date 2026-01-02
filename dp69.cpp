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









// ques: why this if(check==false && i==n)break;
// ans: maan le agr n=4 hai toh esko hame kam se kam 2 hisse me toorna hai but agr for loop chal ke i=4 tk chla gya toh fir 4*f(0) chlega but humne esme 
// ek number ko 2 hisse me tora hini coz 4 pura hi multiply hua hai toh wo case avoid krne ke lea check krege ki agr abi tk check false hai means abi tk 
// break ni hua ye and i==n means i=4 hogya toh ye case ni le skte