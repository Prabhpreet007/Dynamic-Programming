//  Frog Jump (CODING NINJAS)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// MEMOIZATION
// T.C O(n)
// S.C O(n)+O(n)=O(n)

// int Memoization(int n,vector<int>&heights,vector<int>&dp){
// if(n==0)return 0;

// if(dp[n]!=-1)return dp[n];

// int left=Memoization(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
// int right=INT_MAX;
// if(n>1){
// right=Memoization(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
// }
// return dp[n]=min(right,left);

// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> heights(n);
//     for(int i=0;i<n;i++){
//         cin>>heights[i];
//     }
//     vector<int> dp(n,-1);
//     cout<<Memoization(n-1,heights,dp);
//     // *********IMPORTANT*********
// // PASS n-1 in function as this question have 0 based indexing
//     return 0;
// }


// <h1>Tabulation</h1>
// T.C=O(n)
// S.C=O(n) (Stack_space is removed)

// int tab(int n,vector<int>&heights,vector<int> &dp){
// dp[0]=0;
// if(n==0){
//     return dp[n];
// }
// if(n>=1)
// dp[1]=abs(heights[0]-heights[1]);
// if(n==1){
//     return dp[n];
// }

// for(int i=2;i<=n;i++){
//     int left=dp[i-1]+abs(heights[i-1]-heights[i]);
//     int right=dp[i-2]+abs(heights[i-2]-heights[i]);

//     dp[i]=min(left,right);
// }
// return dp[n];
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> heights(n);
//     for(int i=0;i<n;i++){
//         cin>>heights[i];
//     }
//     vector<int> dp(n,-1);
//     cout<<tab(n-1,heights,dp);
//     // *********IMPORTANT*********
// // PASS n-1 in function as this question have 0 based indexing
//     return 0;
// }


// <h1>Space Optimization</h1>
// T.C=O(n)
// S.C=O(1)

int space_opt(int n,vector<int>&heights){
int prev2=0;
if(n==0){
    return prev2;
}
int prev=abs(heights[0]-heights[1]);
if(n==1){
    return prev;
}
for(int i=2;i<=n;i++){
    int left=prev+abs(heights[i-1]-heights[i]);
    int right=prev2+abs(heights[i-2]-heights[i]);
    int curr=min(left,right);

    prev2=prev;
    prev=curr;
}
return prev;

}


int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    cout<<space_opt(n-1,heights);
    // *********IMPORTANT*********
// PASS n-1 in function as this question have 0 based indexing
    return 0;
}