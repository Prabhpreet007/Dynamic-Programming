// Minimum Elements (CN)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// RECURSIVE SOLN
// T.C= O(2^N)
// S.C= O(TARGET)  (if the only element is 1 then it can take target times 1)


    // int findAns(int i,int target,vector<int> &num){
    //     if(i==0){
    //         if(target%num[0]==0){
    //             return target/num[0];
    //         }
    //         else{
    //             return 1e9;
    //         }
    //     }



    //     int notTake=0+findAns(i-1,target,num);
    //     int take=INT_MAX;
    //     if(num[i]<=target){
    //         take=1+findAns(i,target-num[i],num);
    //     }

    //     return min(notTake,take);

    // }

    // int main(){
    //     int n,x;
    //     cin>>n>>x;
    //     vector<int> num(n);
    //     for(int i=0;i<n;i++){
    //         cin>>num[i];
    //     }

    // int ans= findAns(n-1,x,num);
    // if(ans>=1e9){
    //     cout<<-1;
    // }
    // else{
    // cout<<ans;
    // }
    //     return 0;

    // }

// MEMOIZATION
// T.C=O(n*t)  it can go for n times and for each i in n it can go to t times
// S.C=O(n*t)+o(n)

// int findAns(int i,int target,vector<int> &num,vector<vector<int>> &dp){
//         if(i==0){
//             if(target%num[0]==0){
//                 return target/num[0];
//             }
//             else{
//                 return 1e9;
//             }
//         }
//         if(dp[i][target]!=-1){
//             return dp[i][target];
//         }
//         int notTake=0+findAns(i-1,target,num,dp);
//         int take=INT_MAX;
//         if(num[i]<=target){
//             take=1+findAns(i,target-num[i],num,dp);
//         }

//         return dp[i][target]=min(notTake,take);

//     }

//     int main(){
//         int n,x;
//         cin>>n>>x;
//         vector<int> num(n);
//         for(int i=0;i<n;i++){
//             cin>>num[i];
//         }

//     vector<vector<int>>dp(n,vector<int>(x+1,-1));

//     int ans= findAns(n-1,x,num,dp);
//     if(ans>=1e9){
//         cout<<-1;
//     }
//     cout<<ans;
//         return 0;

//     }

// TABULATION

//T.C= O(N*W)  (its exactly n*w so in this tabulation is a bit slow as it will discover each and every column 
// but in memoization not every block is taken)

//S.C= O(N*TARGET)

// int minimumElements(vector<int> &num, int target)
// {
//     int n=num.size();

//     //make sure to make dp 0 first
//     vector<vector<int>>dp(n,vector<int>(target+1,0));
    
//     for(int i=0;i<=target;i++){
//         if(i%num[0]==0){
//             dp[0][i]=i/num[0];
//         }
//         else{
//             dp[0][i]=1e9;
//         }
//     }

//     for(int i=1;i<n;i++){
//         for(int T=0;T<=target;T++){
//         int notTake=0+dp[i-1][T];
//         int take=INT_MAX;
//         if(num[i]<=T){
//             take=1+dp[i][T-num[i]];
//         }

//          dp[i][T]=min(notTake,take);
//         }
//     }

//     int ans= dp[n-1][target];
//     if(ans>=1e9){
//         return -1;
//     }
//     return ans;
    
// }

// SPACE OPTIMIZATION
//T.C= O(N*W)
//S.C= O(TARGET)

// int minimumElements(vector<int> &num, int target)
// {
//     int n=num.size();

//     //make sure to make dp 0 first
//     vector<int>prev(target+1,0),curr(target+1,0);
    
//     for(int i=0;i<=target;i++){
//         if(i%num[0]==0){
//             prev[i]=i/num[0];
//         }
//         else{
//             prev[i]=1e9;
//         }
//     }

//     for(int i=1;i<n;i++){
//         for(int T=0;T<=target;T++){
//         int notTake=0+prev[T];
//         int take=INT_MAX;
//         if(num[i]<=T){
//             take=1+curr[T-num[i]];
//         }

//          curr[T]=min(notTake,take);
//         }
//         prev=curr;
//     }

//     int ans= prev[target];
//     if(ans>=1e9){
//         return -1;
//     }
//     return ans;
    
// }

