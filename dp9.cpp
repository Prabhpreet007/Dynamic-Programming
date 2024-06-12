// Minimum Path Sum (CODING NINJAS) 
// 64. Minimum Path Sum (LEETCODE)


#include<iostream>
#include<vector>
using namespace std;

//RECURSIVE RELATION
// T.C=O(2^mn)
// S.C=O((m-1)+(n-1)) 
//     int findAns(int n,int m,vector<vector<int>> &grid){
//     if(n==0 && m==0){
//         return grid[n][m];
//     }
//     if(n<0 || m<0){
//         return 1e9;
//     }
//     int right=findAns(n,m-1, grid)+grid[n][m];
//     int top=findAns(n-1,m,grid)+grid[n][m];

//     return min(right,top);
// }

// int main(){
// int n,m;
// cin>>n>>m;

// vector<vector<int>> grid(n,vector<int>(m));

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>grid[i][j];
//     }
// }
// cout<<findAns(n-1,m-1,grid);
//     return 0;
// }


//MEMOIZATION
// T.C=O(m*n)
// S.C=O((m-1)+(n-1))+O(n*m)

// int findAns(int n,int m,vector<vector<int>> &grid,vector<vector<int>>&dp){
//     if(n==0 && m==0){
//         return grid[n][m];
//     }
//     if(n<0 || m<0){
//         return 1e9;
//     }
//     if(dp[n][m]!=-1)return dp[n][m];
//     int right=findAns(n,m-1, grid,dp)+grid[n][m];
//     int top=findAns(n-1,m,grid,dp)+grid[n][m];

//     return dp[n][m]=min(right,top);

// }

// int main(){
// int n,m;
// cin>>n>>m;

// vector<vector<int>> grid(n,vector<int>(m));

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>grid[i][j];
//     }
// }
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     cout<<findAns(n-1,m-1,grid,dp);    
        
//         return 0;
// }


//TABULATION
// T.C=O(m*n)
// S.C=O(m*n)

    int findAns(int n,int m,vector<vector<int>> &grid,vector<vector<int>>&dp){

    dp[0][0]=grid[0][0];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0)continue;
            int right=1e9;int top=1e9;
            if(i>0){
                top=grid[i][j]+dp[i-1][j];
            }
            if(j>0){
                right=grid[i][j]+dp[i][j-1];
            }

            dp[i][j]=min(right,top);
        }
    }
    return dp[n][m];
}

int main(){
int n,m;
cin>>n>>m;

vector<vector<int>> grid(n,vector<int>(m));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
}
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<findAns(n-1,m-1,grid,dp);    
        
        return 0;
}