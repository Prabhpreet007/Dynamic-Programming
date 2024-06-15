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
//S.C=O(n*k)+O(n)=O(n*k)

bool findAns(int i,int sum,int k,int n,vector<int>&arr,vector<vector<int>>&dp){
    if(sum==k){
        return true;
    }
    if(sum>k){
        return false;
    }
    if(sum<k && i==n){
        return false;
    }

    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }

    bool take=findAns(i+1,sum+arr[i],k,n,arr,dp);
    bool notTake=findAns(i+1,sum,k,n,arr,dp);

    return dp[i][sum]=take||notTake;
}


int main(){

int n;
int k;
cin>>n>>k;

vector<int>arr(n);

for(int i=0;i<n;i++){
    cin>>arr[i];
}

    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    cout<< findAns(0,0,k,n,arr,dp);
    return 0;
}