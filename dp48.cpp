// Matrix Chain Multiplication(C.N)

// T.C=exponential
// S.C=O(n)
#include <bits/stdc++.h> 


    int findAns(int i,int j,vector<int>&nums){
        if(i==j)return 0;

        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=nums[i-1]*nums[k]*nums[j]+findAns(i,k,nums)+findAns(k+1,j,nums);
            if(steps<mini)mini=steps;
        }
        return mini;
    }
int matrixMultiplication(vector<int> &nums, int N)
{
    
        return findAns(1,N-1,nums);
}

// MEMOIZATION
// T.C=O(N*N)*N
    //    I AND J EACH WILL HAVE N STATES SO N*N AND FOR THE REST N ITS FOR LOOP OF K
// S.C=O(N*N)+O(N)

#include <bits/stdc++.h> 


    int findAns(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i==j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=nums[i-1]*nums[k]*nums[j]+findAns(i,k,nums,dp)+findAns(k+1,j,nums,dp);
            if(steps<mini)mini=steps;
        }
        return dp[i][j]= mini;
    }
    
int matrixMultiplication(vector<int> &nums, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,-1));
        return findAns(1,N-1,nums,dp);
}