// 300. Longest Increasing Subsequence

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;


//RECURSIVE
// T.C=O(2^N)
// S.C=O(N)


// int findAns(int i,int prevIndex,vector<int>& nums){

//         if(i>=nums.size())return 0;

//         int ans=0;
//         if(prevIndex==-1 || nums[i]>nums[prevIndex]){
//             ans=max(1+findAns(i+1,i,nums),0+findAns(i+1,prevIndex,nums));
//         }
//         else{
//             ans=findAns(i+1,prevIndex,nums);
//         }
//         return ans;
//     }

// int main(){
// int n;
// cin>>n;
// vector<int>nums(n);
// for(int i=0;i<n;i++){
//     cin>>nums[i];
// }
//     int i=0;
//     int prevIndex=-1;
        
//         cout<< findAns(i,prevIndex,nums);

//     return 0;
// }

// MEMOIZATION
//T.C=O(N*(N+1))
//S.C=O(N*(N*1))+O(N)

    // int findAns(int i,int prevIndex,vector<int>& nums,vector<vector<int>>& dp){

    //     if(i>=nums.size())return 0;

    //     if(dp[i][prevIndex+1]!=-1){
    //         return dp[i][prevIndex+1];
    //     }

    //     int ans=0;
    //     if(prevIndex==-1 || nums[i]>nums[prevIndex]){
    //         ans=max(1+findAns(i+1,i,nums,dp),0+findAns(i+1,prevIndex,nums,dp));
    //     }
    //     else{
    //         ans=findAns(i+1,prevIndex,nums,dp);
    //     }
        
    //     return dp[i][prevIndex+1]=ans;
    // }

    // int main(){
    // int n;
    // cin>>n;
    // vector<int>nums(n);
    // for(int i=0;i<n;i++){
    //     cin>>nums[i];
    // }
    //     int i=0;
    //     int prevIndex=-1;
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));

    //         cout<< findAns(i,prevIndex,nums,dp);

    //     return 0;
    // }


//TABULATTION
//T.C=O(N*(N+1))
//S.C=O(N*(N*1))

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
        int i=0;
        int prevIndex=-1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int prevIndex=-1;prevIndex<i;prevIndex++){
                int ans=0;
                if(prevIndex==-1 || nums[i]>nums[prevIndex]){
                    ans=max(1+dp[i+1][i+1],0+dp[i+1][prevIndex+1]);
                }
                else{
                    ans=dp[i+1][prevIndex+1];
                }

                dp[i][prevIndex+1]=ans;
            }
        }
        cout<< dp[0][prevIndex+1];
    return 0;
}


//S.C= o(n)
// T.c=o(n^2) nearly

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,1);

        int maxi=1;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;

    }