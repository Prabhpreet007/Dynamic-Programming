// 416. Partition Equal Subset Sum (LEETCODE & CODING NINJAS)


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//RECURSIVE SOLUTION
// T.C=o(2^n)
// S.C=O(n)+O(n)=O(n)

    // bool findAns(int i,int sum,int target,vector<int>&nums,vector<int>&v){
    //     if(sum==target){
    //         int x=0;
    //         int sum_v=0;
    //         int j=0;
    //         while(j<v.size()&&x<nums.size()){
    //             if(nums[x]!=v[j]){
    //                 sum_v+=nums[x];
    //                 x++;
    //             }
    //             else{
    //                 x++;
    //                 j++;
    //             }
    //         }
    //         while(x!=nums.size()){
    //             sum_v+=nums[x];
    //             x++;
    //         }

    //         if(sum==sum_v)return true;
    //         else{
    //             return false;
    //         }
    //     }
    //     if(i==nums.size()){
    //         return false;
    //     }

    //     v.push_back(nums[i]);
        
    //     bool inc=findAns(i+1,sum+nums[i],target,nums,v);
    //     v.pop_back();
    //     bool not_inc=findAns(i+1,sum,target,nums,v);

    //     return inc||not_inc;

    // }

    // int main(){
    //     int n;
    //     cin>>n;
    //     vector<int>nums(n);
    //     for(int i=0;i<n;i++){
    //         cin>>nums[i];
    //     }

    //     int sum=0;
    //     for(auto i:nums){
    //         sum+=i;
    //     }
    //     if(sum%2!=0){
    //         cout<< false;            
    //         }

    //     else{
    //     int target=sum/2;
    //     vector<int>v;
    //     cout<<findAns(0,0,target,nums,v);

    //     }


    //     return 0;
    // }


//MEMOIZATION
//T.C=O(N*(TARGET+1))
//S.C=O(N*(TARGET+1))+O(n)->stack space

    // bool findAns(int i,int sum,int target,vector<int>&nums,vector<int>&v,vector<vector<int>>&dp){
    //     if(sum==target){
    //         int x=0;
    //         int sum_v=0;
    //         int j=0;
    //         while(j<v.size()&&x<nums.size()){
    //             if(nums[x]!=v[j]){
    //                 sum_v+=nums[x];
    //                 x++;
    //             }
    //             else{
    //                 x++;
    //                 j++;
    //             }
    //         }
    //         while(x!=nums.size()){
    //             sum_v+=nums[x];
    //             x++;
    //         }

    //         if(sum==sum_v)return true;
    //         else{
    //             return false;
    //         }
    //     }
    //     if(i==nums.size()){
    //         return false;
    //     }
    //     if(sum>target){
    //         return false;
    //     }

    //     if(dp[i][sum]!=-1)return dp[i][sum];

    //     v.push_back(nums[i]);
        
    //     bool inc=findAns(i+1,sum+nums[i],target,nums,v,dp);
    //     v.pop_back();
    //     bool not_inc=findAns(i+1,sum,target,nums,v,dp);

    //     return dp[i][sum]=inc||not_inc;

    // }


    // int main(){
    //     int n;
    //     cin>>n;
    //     vector<int>nums(n);
    //     for(int i=0;i<n;i++){
    //         cin>>nums[i];
    //     }

    //     int sum=0;
    //     for(auto i:nums){
    //         sum+=i;
    //     }

    //     if(sum%2!=0){
    //         cout<< false;            
    //         }
    //     else{
    //     int target=sum/2;
    //     vector<int>v;
    //     vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));

    //     cout<<findAns(0,0,target,nums,v,dp);

    //     }


    //     return 0;
    // }


// TABULATION




