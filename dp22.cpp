// 518. Coin Change II(LEETCODE)
// Ways To Make Coin Change(CN)

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// T.C= GREATER THAN O(2^N) SO ITS EXPONENTIAL
// S.C=O(TARGET)

//     int findAns(int i,int target,vector<int>& coins){

//         if(target==0)return 1;
//         if(i==0){

//             if(target%coins[i]==0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(target<0)return 0;

//         int take=0;
//         if(coins[i]<=target){
//             take=findAns(i,target-coins[i],coins);
//         }
//         int notTake=findAns(i-1,target,coins);
//         return take+notTake;
//     }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     int amount;
//     cin>>amount;

//         int sum=0;
//         int cnt=0;
//         cout<<findAns(n-1,amount,coins);

// }

// MEMOIZATION

// T.C=O(N*T)
// S.C=O(N*T)+O(N)

// int findAns(int i,int target,vector<int>& coins,vector<vector<int>>& dp){

//     if(target==0)return 1;
//     if(i==0){

//         if(target%coins[i]==0){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(target<0)return 0;
//     if(dp[i][target]!=-1){
//         return dp[i][target];
//     }

//     int take=0;
//     if(coins[i]<=target){
//         take=findAns(i,target-coins[i],coins,dp);
//     }
//     int notTake=findAns(i-1,target,coins,dp);
//     return dp[i][target]=take+notTake;
// }

//     int main(){
//     int n;
//     cin>>n;
//     vector<int>coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     int amount;
//     cin>>amount;

//         int sum=0;
//         int cnt=0;

//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));

//         cout<<findAns(n-1,amount,coins,dp);

// }

// TABULATION
//  T.C=O(N*T)
//  S.C=O(N*T)

int findAns(int target, vector<int> &coins, vector<vector<int>> &dp)
{

    for (int t = 0; t <= target; t++)
    {
        if (t % coins[0] == 0)
        {
            dp[0][t] = 1;
        }
        else
        {
            dp[0][t] = 0;
        }
    }

    for (int i = 1; i < coins.size(); i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int take = 0;
            if (coins[i] <= t)
            {
                take = dp[i][t - coins[i]];
            }
            int notTake = dp[i - 1][t];
            dp[i][t] = take + notTake;
        }
    }
    return dp[coins.size() - 1][target];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    int sum = 0;
    int cnt = 0;

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    cout << findAns(amount, coins, dp);
}