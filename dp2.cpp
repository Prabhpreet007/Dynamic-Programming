//70. Climbing Stairs(LEETCODE)

// <h1>Memoization</h1>
// T.C=O(n)
// S.C=O(n)+O(n)=O(n)
//   Stack_space + Array 

#include<iostream>
#include<vector>
using namespace std;

// int Memoization(int n,vector<int>& dp){
// if(n==0 || n==1){
//     return 1;
// }
// if(dp[n]!=-1){
// return dp[n];
// }
// return dp[n]=Memoization(n-1,dp)+Memoization(n-2,dp);
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout<<Memoization(n,dp);

//     return 0;
// }


// <h1>Tabulation</h1>
// T.C=O(n)
// S.C=O(n) (Stack_space is removed)

// int Tabulation(int n,vector<int>& dp){
// dp[0]=1;
// dp[1]=1;

// if(n==1 || n==0){
//     return dp[n];
// }

// for(int i=2;i<=n;i++){
// dp[i]=dp[i-1]+dp[i-2];
// }
// return dp[n];
// }


// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout<<Tabulation(n,dp);

//     return 0;
// }



// <h1>Space Optimization</h1>
// T.C=O(n)
// S.C=O(1)

int Space_opt(int n,vector<int>& dp){
int prev2=1;
int prev=1;
if(n==1 || n==0){
return 1;
}
for(int i=2;i<=n;i++){
    int curr=prev+prev2;
    prev2=prev;
    prev=curr;
}
return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<Space_opt(n,dp);

    return 0;
}