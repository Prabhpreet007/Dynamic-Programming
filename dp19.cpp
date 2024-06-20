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

//T.C=O(n*w)
//S.C=O(n*w)+O(n)

int findAns(int i,int maxWeight,vector<int> weight,vector<int> value,vector<vector<int>>& dp){
	if(i==0){
		if(maxWeight>=weight[i]){
			return value[i];
		}
		else{
			return 0;
		}
	}

	if(dp[i][maxWeight]!=-1)return dp[i][maxWeight];

	int take=INT_MIN;
	if(weight[i]<=maxWeight){
		take=value[i]+findAns(i-1,maxWeight-weight[i],weight,value,dp);
	}
	int notTake=0+findAns(i-1,maxWeight,weight,value,dp);

	return dp[i][maxWeight]=max(take,notTake);
}

int main(){

int n;
cin>>n;
vector<int>weight(n);
vector<int>value(n);

for(int i=0;i<n;i++){
    cin>>weight[i];
}

for(int i=0;i<n;i++){
    cin>>value[i];
}

int maxWeight;
cin>>maxWeight;

vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));

cout<<findAns(n-1,maxWeight,weight,value,dp);

    return 0;
}