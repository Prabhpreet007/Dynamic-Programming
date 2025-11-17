// Subset Sum Equal To K (CODING NINJAS)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


//RECURSIVE SOLUTION
// T.C=O(2^n)
// S.C=O(n)

// bool findAns(int i,int sum,int k,int n,vector<int>&arr){
//     if(sum==k){
//         return true;
//     }
//     if(sum>k){
//         return false;
//     }
//     if(sum<k && i==n){
//         return false;
//     }

//     bool take=findAns(i+1,sum+arr[i],k,n,arr);
//     bool notTake=findAns(i+1,sum,k,n,arr);

//     return take||notTake;
// }


// int main(){
// int n;
// int k;
// cin>>n>>k;

// vector<int>arr(n);

// for(int i=0;i<n;i++){
//     cin>>arr[i];
// }

// cout<<findAns(0,0,k,n,arr);

//     return 0;
// }



//MEMOIZATION
//T.C=O(n)
//S.C=O(n*k)+O(n)

// bool findAns(int i,int sum,int k,int n,vector<int>&arr,vector<vector<int>>&dp){
//     if(sum==k){
//         return true;
//     }
//     if(sum>k){
//         return false;
//     }
//     if(sum<k && i==n){
//         return false;
//     }

//     if(dp[i][sum]!=-1){
//         return dp[i][sum];
//     }

//     bool take=findAns(i+1,sum+arr[i],k,n,arr,dp);
//     bool notTake=findAns(i+1,sum,k,n,arr,dp);

//     return dp[i][sum]=take||notTake;
// }


// int main(){

// int n;
// int k;
// cin>>n>>k;

// vector<int>arr(n);

// for(int i=0;i<n;i++){
//     cin>>arr[i];
// }

//     vector<vector<int>>dp(n,vector<int>(k+1,-1));
//     cout<< findAns(0,0,k,n,arr,dp);
//     return 0;
// }



//TABULATION
//T.C=O(n)
//S.C=O(n*k)   now stack space is removed


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}