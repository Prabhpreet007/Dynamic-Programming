//  Unique Paths II (CODING NINJAS)
#include<iostream>
#include<vector>
using namespace std;


// RECURSIVE RELATION
// T.C=O(2^mn)
// S.C=O((m-1)+(n-1))     ->WORST CASE

//     int mod=1000000007;
// int findAns(int n,int m,vector<vector<int>>&mat){
//     if(n>=0 && m>=0 && mat[n][m]==-1){
//         return 0;
//     }
//     if(n==0 && m==0 ){
//         return 1;
//     }
//     if(n<0 || m<0){
//         return 0;
//     }

//     int top=findAns(n-1, m, mat);
//     int left=findAns(n, m-1, mat);

//     return (top+left)%mod;
// }

// int main(){

// int n;
// int m;
// cin>>n>>m;
// vector<vector<int>> mat(n,vector<int>(m));

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>mat[i][j];
//     }
// }

//     int x=findAns(n-1,m-1,mat);
//     cout<<x%mod;
// }

//MEMOIZATION
// T.C=O(m*n)
// S.C=O((m-1)+(n-1))+O(n*m)

// int mod=1000000007;

// int findAns(int n,int m,vector<vector<int>>&mat,vector<vector<int>>&dp){
//     if(n>=0 && m>=0 && mat[n][m]==-1){
//         return 0;
//     }
//     if(n==0 && m==0 &&mat[n][m]!=-1){
//         return 1;
//     }
//     if(n<0 || m<0){
//         return 0;
//     }

//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }

//     int top=findAns(n-1, m, mat,dp);
//     int left=findAns(n, m-1, mat,dp);

//     return dp[n][m]=(top+left)%mod;
// }
// int main(){

// int n;
// int m;
// cin>>n>>m;
// vector<vector<int>> mat(n,vector<int>(m));

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>mat[i][j];
//     }
// }
//     vector<vector<int>>dp (n,vector<int>(m,-1));
//     int x=findAns(n-1,m-1,mat,dp);
//     cout<<x%mod;
// }


//TABULATION
// T.C=O(m*n)
// S.C=O(m*n)

int mod=1000000007;

int findAns(int n,int m,vector<vector<int>>&mat,vector<vector<int>>&dp){
    dp[0][0]=1;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0)continue;
            if (mat[i][j] == -1) {
              dp[i][j] = 0;
              continue;
            }
            int bottom=0;int right=0;
            if(i>0){
                bottom=dp[i-1][j];
            }
            if(j>0){
                right=dp[i][j-1];
            }
            dp[i][j]=(bottom+right)%mod;
        }
    }

    return dp[n][m];
}

int main(){

int n;
int m;
cin>>n>>m;
vector<vector<int>> mat(n,vector<int>(m));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>mat[i][j];
    }
}
    vector<vector<int>>dp (n,vector<int>(m,-1));
    int x=findAns(n-1,m-1,mat,dp);
    cout<<x%mod;
}