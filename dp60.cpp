// https://neetcode.io/problems/paint-house?list=neetcode250
// Paint House

// T.C=O(n*4*3) = O(n)

class Solution {
public:

    int findAns(vector<vector<int>>& costs,int n,int ind,int prev,vector<vector<int>>& dp){

        if(ind>=n){
            return 0;
        }

        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

        int mini=INT_MAX;
        for(int i=0;i<3;i++){
            if(prev!=i){
                int curr=findAns(costs,n,ind+1,i,dp)+costs[ind][i];
                mini=min(mini,curr);
            }
        }

        return dp[ind][prev+1] = mini;

    }

    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return findAns(costs,n,0,-1,dp);
    }
};

