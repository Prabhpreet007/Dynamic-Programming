// TARGET SUM ( 494 - LC) & (CN)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//RECURSIVE SOLN
//T.C=O(2^n)
//S.C=O(n)

// int findAns(int i,vector<int>& nums,int target,int currSum){
//         if(i<0){
//             if(currSum==target){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
        

//         int Mtake=findAns(i-1,nums,target,currSum-nums[i]);
//         int Ptake=findAns(i-1,nums,target,currSum+nums[i]);

//         return Mtake+Ptake;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int cnt=0;
//         int n=nums.size();
//         return findAns(n-1,nums,target,0);
//     }



//MEMOIZATION (VERY IMPORTANT)
//T.C=O(n * (2 * sum + 1))
//S.C=O(n * (2 * sum + 1))



// int findAns(int i, vector<int>& nums, int target, int currSum, vector<vector<int>>& dp, int offset) {
//     if (i < 0) {
//         return currSum == target ? 1 : 0;
//     }
//     if (dp[i][currSum + offset] != -1) {
//         return dp[i][currSum + offset];
//     }
//     int Mtake = findAns(i - 1, nums, target, currSum - nums[i], dp, offset);
//     int Ptake = findAns(i - 1, nums, target, currSum + nums[i], dp, offset);

//     return dp[i][currSum + offset] = Mtake + Ptake;
// }

// int targetSum(int n, int target, vector<int>& nums) {
//     int sum = accumulate(nums.begin(), nums.end(), 0);
//     int offset = sum;  // Offset to handle negative indices
//     vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
//     return findAns(n - 1, nums, target, 0, dp, offset);
// }


