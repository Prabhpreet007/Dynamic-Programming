// 0 1 Knapsack (CODING NINJAS)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//T.C=O(2^N)
//S.C=O(N)

// int findAns(int i,int maxWeight,vector<int> weight,vector<int> value){
// 	if(i==0){
// 		if(maxWeight>=weight[i]){
// 			return value[i];
// 		}
// 		else{
// 			return 0;
// 		}
// 	}

// 	int take=INT_MIN;
// 	if(weight[i]<=maxWeight){
// 		take=value[i]+findAns(i-1,maxWeight-weight[i],weight,value);
// 	}
// 	int notTake=0+findAns(i-1,maxWeight,weight,value);

// 	return max(take,notTake);
// }

// int main(){

// int n;
// cin>>n;
// vector<int>weight(n);
// vector<int>value(n);

// for(int i=0;i<n;i++){
//     cin>>weight[i];
// }

// for(int i=0;i<n;i++){
//     cin>>value[i];
// }

// int maxWeight;
// cin>>maxWeight;
// cout<<findAns(n-1,maxWeight,weight,value);
//     return 0;
// }


//MEMOIZATION
//T.C=O(n*w)
//S.C=O(n*w)+O(n)

// int findAns(int i,int maxWeight,vector<int> weight,vector<int> value,vector<vector<int>>& dp){
// 	if(i==0){
// 		if(maxWeight>=weight[i]){
// 			return value[i];
// 		}
// 		else{
// 			return 0;
// 		}
// 	}

// 	if(dp[i][maxWeight]!=-1)return dp[i][maxWeight];

// 	int take=INT_MIN;
// 	if(weight[i]<=maxWeight){
// 		take=value[i]+findAns(i-1,maxWeight-weight[i],weight,value,dp);
// 	}
// 	int notTake=0+findAns(i-1,maxWeight,weight,value,dp);

// 	return dp[i][maxWeight]=max(take,notTake);
// }

// int main(){

// int n;
// cin>>n;
// vector<int>weight(n);
// vector<int>value(n);

// for(int i=0;i<n;i++){
//     cin>>weight[i];
// }

// for(int i=0;i<n;i++){
//     cin>>value[i];
// }

// int maxWeight;
// cin>>maxWeight;

// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));

// cout<<findAns(n-1,maxWeight,weight,value,dp);

//     return 0;
// }




// TABULATION
//T.C=O(n*w)
//S.C=O(n*w)
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
//IMPORTANT (MAKE SURE TO INITIALIZE THE DP ARRAY WITH 0)


	for(int i=wt[0];i<=maxWeight;i++){
		dp[0][i]=val[0];
	}

	for(int i=1;i<n;i++){
		for(int w=0;w<=maxWeight;w++){
			int take=INT_MIN;
		if(wt[i]<=w){
			take=val[i]+dp[i-1][w-wt[i]];
		}	
		int notTake=0+dp[i-1][w];

				dp[i][w]=max(take,notTake);

		}
	}
	return dp[n-1][maxWeight];
}