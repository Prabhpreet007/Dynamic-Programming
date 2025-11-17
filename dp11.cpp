// Maximum Path Sum in the matrix (CODING NINJAS)   GOOD QUESTION

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// RECURSIVE SOLUTION
// T.C=O(M)*O(3^N)
// S.C=O(N)

// int findAns(int n,int m,vector<vector<int>> &matrix){
//     if(n==0){
//         return matrix[n][m];
//     }

//     int maxi=INT_MIN;
//     int ttl=INT_MIN,tt=INT_MIN,ttr=INT_MIN;


//     tt=findAns(n-1,m,matrix)+matrix[n][m];


//     if(m-1>=0){
//              ttl=findAns(n-1,m-1,matrix)+matrix[n][m];
//         }


//     if(m+1<matrix[0].size()){
//             ttr=findAns(n-1,m+1,matrix)+matrix[n][m];
//         }
//     maxi=max(maxi,max(ttl,max(tt,ttr)));
//     return maxi;
// }

// int main(){
// int n,m;
// cin>>n>>m;
// vector<vector<int>> matrix(n,vector<int>(m));

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>matrix[i][j];
//     }
// }

// int maxi=INT_MIN;
// for(int i=0;i<m;i++){
//     maxi=max(findAns(n-1,i,matrix),maxi);
// }
// cout<<maxi;

//     return 0;
// }

// MEMOIZATION
//  T.C= (o(m)*o(n))+o(n)=>o(n*m)
//  S.C= o(n*m)+o(n)=>o(n*m)     dp array & stack space

// int findAns(int n,int m,vector<vector<int>> &matrix,vector<vector<int>>&dp){
//     if(n==0){
//         return matrix[n][m];
//     }

// if(dp[n][m]!=-1)return dp[n][m];

//     int maxi=INT_MIN;
//     int ttl=INT_MIN,tt=INT_MIN,ttr=INT_MIN;

//     if(m-1>=0){
//              ttl=findAns(n-1,m-1,matrix,dp)+matrix[n][m];
//         }

//         tt=findAns(n-1,m,matrix,dp)+matrix[n][m];

//     if(m+1<matrix[0].size()){
//             ttr=findAns(n-1,m+1,matrix,dp)+matrix[n][m];
//         }
//         maxi=max(maxi,max(ttl,max(tt,ttr)));
//         return dp[n][m]=maxi;
// }

// int main(){
// int n,m;
// cin>>n>>m;
// vector<vector<int>> matrix(n,vector<int>(m));

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>matrix[i][j];
//     }
// }
// vector<vector<int>>dp(n,vector<int>(m,-1));

// int maxi=INT_MIN;
// for(int i=0;i<m;i++){
//     maxi=max(findAns(n-1,i,matrix,dp),maxi);
// }
// cout<<maxi;

//     return 0;
// }

// TABULATION

int findAns(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    for (int i = 0; i < matrix[0].size(); i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            int maxi = INT_MIN;
            int ttl = INT_MIN, tt = INT_MIN, ttr = INT_MIN;

            if (j - 1 >= 0)
            {
                ttl = dp[i - 1][j - 1] + matrix[i][j];
            }

            tt = dp[i - 1][j] + matrix[i][j];

            if (j + 1 < matrix[0].size())
            {
                ttr = dp[i - 1][j + 1] + matrix[i][j];
            }
            maxi = max(maxi, max(ttl, max(tt, ttr)));

            dp[i][j] = maxi;
        }
    }
    return dp[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;
    maxi = max(findAns(n - 1, m - 1, matrix, dp), maxi);
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }

    cout << maxi;
    return 0;
}