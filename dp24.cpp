// Rod cutting problem(CN)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//RECURSIVE RELATION
// T.C =exponential (greater than O(2^n))
// S.C =O(n)

// int findAns(int i,int n,vector<int>& price){
//     if(i==0){
//         return price[0]*n;
//     }

//     int take=INT_MIN;
//     if(i+1<=n){
//         take=price[i]+findAns(i,n-(i+1),price);
//     }
//     int notTake=0+findAns(i-1,n,price);
//     return max(take,notTake);
// }

// int main(){
// int n;
// cin>>n;
// vector<int>price(n);
// for(int i=0;i<n;i++)
// {
//     cin>>price[i];
// }

// cout<<findAns(n-1,n,price);
//     return 0;
// }


//MEMOIZATION
//T.C=O(n)
//S.C=O(n)+O(n*(n+1))

// int findAns(int i,int n,vector<int>& price,vector<vector<int>>&dp){
//     if(i==0){
//         return price[0]*n;
//     }

//     if(dp[i][n]!=-1)return dp[i][n];

//     int take=INT_MIN;
//     if(i+1<=n){
//         take=price[i]+findAns(i,n-(i+1),price,dp);
//     }
//     int notTake=0+findAns(i-1,n,price,dp);
//     return dp[i][n]=max(take,notTake);
// }


// int main(){
// int n;
// cin>>n;
// vector<int>price(n);
// for(int i=0;i<n;i++)
// {
//     cin>>price[i];
// }
    
// vector<vector<int>>dp(n,vector<int>(n+1,-1));

// cout<<findAns(n-1,n,price,dp);
//     return 0;
// }


//TABULTION
// T.C=O(N*(N+1))
// S.C=O(N*(N+1))

// int findAns(int n,vector<int>& price,vector<vector<int>>&dp){


//     for(int i=0;i<=n;i++){
//         dp[0][i]=price[0]*i;
//     }

//     for(int i=1;i<n;i++){
//         for(int j=0;j<=n;j++){
//             int take=INT_MIN;
//             if(i+1<=j){
//                 take=price[i]+dp[i][j-(i+1)];
//             }
//             int notTake=0+dp[i-1][j];
//             dp[i][j]=max(take,notTake);
//         }
//     }

    
//     return dp[n-1][n];
// }

// int main(){
// int n;
// cin>>n;
// vector<int>price(n);
// for(int i=0;i<n;i++)
// {
//     cin>>price[i];
// }
    
// vector<vector<int>>dp(n,vector<int>(n+1,0));

// cout<<findAns(n,price,dp);
//     return 0;
// }


//Space Opt
// T.C=O(N*(N+1))
// S.C=O(N+1)

int findAns(int n,vector<int>& price,vector<vector<int>>&dp){
vector<int>prev(n+1),curr(n+1);

    for(int i=0;i<=n;i++){
        curr[i]=price[0]*i;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int take=INT_MIN;
            if(i+1<=j){
                take=price[i]+curr[j-(i+1)];
            }
            int notTake=0+prev[j];
            curr[j]=max(take,notTake);
            prev=curr;
        }
    }

    
    return prev[n];
}

int main(){
int n;
cin>>n;
vector<int>price(n);
for(int i=0;i<n;i++)
{
    cin>>price[i];
}
    
vector<vector<int>>dp(n,vector<int>(n+1,0));

cout<<findAns(n,price,dp);
    return 0;
}