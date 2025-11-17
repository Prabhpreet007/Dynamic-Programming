// //Count Subsets with Sum K (coding ninjas)

// #include<iostream>
// #include<vector>
// #include<limits.h>
// using namespace std;


// int findAns(vector<int>& arr, int& k,int sum,int i,int& count){
// 	if(sum==k){
// 		count++;
// 		return 1;
// 	}
// 	if(sum>k){
// 		return 0;
// 	}
// 	if(i>=arr.size()){
// 		return 0;
// 	}

// 	//take
// 	int take=findAns(arr,k,sum+arr[i],i+1,count);

// 	//not take
// 	int notTake=findAns(arr,k,sum,i+1,count);
// 	return take+notTake;
// }

// int main(){
// int n;
// int k;
// cin>>n>>k;

// vector<int>arr(n);

// for(int i=0;i<n;i++){
//     cin>>arr[i];
// }

// int sum=0;
// int i=0;
// int count=0;
// cout<<findAns(arr,k,sum,i,count);
//     return 0;
// }











#include <vector>
using namespace std;
int mod=1e9+7;

int findAns(int i, vector<int>& arr, int k, vector<vector<int>>& dp) {

     if(i==0){
		
		if(k==0){
			if(arr[0]==0){
				return 2;
			}
			else return 1;
		}
		
		else if(arr[0]==k){
				return 1;
			}
			else return 0;
	}

    if (dp[i][k] != -1) {
        return dp[i][k];
    }

    int take = 0;
    if (arr[i] <= k) {
        take = findAns(i - 1, arr, k-arr[i], dp);
    }
    
    int notTake = findAns(i - 1, arr, k, dp);

    return dp[i][k] = (take + notTake)%mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findAns(n-1, arr, k, dp);
}
