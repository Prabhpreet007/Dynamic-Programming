//  Maximum sum of non-adjacent elements (CODING NINJAS)

#include<iostream>
#include<vector>
using namespace std;


// ***********Memoization**********

// T.C= O(N)
// S.C=O(N)+O(N)

// int Memoization(int n,vector<int>&nums,vector<int>&dp){

// if(n==0)return nums[0];
// if(n<0)return 0;
// if(dp[n]!=-1){
//     return dp[n];
// }


// int left=nums[n]+Memoization(n-2,nums,dp);
// int right=0+Memoization(n-1,nums,dp);

// return dp[n]=max(left,right);

// }

// int main(){
// int n;
// cin>>n;
// vector<int> nums(n);
// for(int i=0;i<n;i++){
//     cin>>nums[i];
// }

// vector<int> dp(n,-1);
// cout<<Memoization(n-1,nums,dp);
// // *********IMPORTANT*********
// // PASS n-1 in function as this question have 0 based indexing

//     return 0;
// }



// *******Tabulation***********

// T.C= O(N)
// S.C=O(N)


// int Tab(int n,vector<int>& nums,vector<int> &dp){
// dp[0]=nums[0];
// dp[1]=max(nums[0],nums[1]);

// if(n<=1)return dp[n];
// for(int i=2;i<=n;i++){
//     int left=nums[i]+dp[i-2];
//     int right=0+dp[i-1];

//     dp[i]=max(left,right);

// }
// return dp[n];
// }


// int main(){
// int n;
// cin>>n;
// vector<int> nums(n);
// for(int i=0;i<n;i++){
//     cin>>nums[i];
// }

// vector<int> dp(n,-1);
// cout<<Tab(n-1,nums,dp);
// // *********IMPORTANT*********
// // PASS n-1 in function as this question have 0 based indexing

//     return 0;
// }







// *******SPACE_OPTIMISATION************
// T.C= O(N)
// S.C=O(1)

int Space_Opt(int n,vector<int>&nums){
int prev2=nums[0];
if(n==0)return prev2;

int prev=max(nums[0],nums[1]);
if(n==1)return prev;

for(int i=2;i<=n;i++){
    int left=nums[i]+prev2;
    int right=0+prev;

    int curr=max(left,right);

    prev2=prev;
    prev=curr;
}
return prev;
}

int main(){
int n;
cin>>n;
vector<int> nums(n);
for(int i=0;i<n;i++){
    cin>>nums[i];
}
cout<<Space_Opt(n-1,nums);
// *********IMPORTANT*********
// PASS n-1 in function as this question have 0 based indexing

    return 0;
}