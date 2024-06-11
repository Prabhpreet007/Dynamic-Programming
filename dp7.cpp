// Unique Paths  (CODING NINJAS)

#include<iostream>
#include<vector>
using namespace std;


// recursive soln
// T.C=O(2^mn)
// S.C=O((m-1)+(n-1))     ->WORST CASE
// int findAns(int m,int n){
// if(m==0 && n==0){
// 	return 1;
// }
// if(m<0 || n<0){
// 	return 0;
// }

// int left=findAns(m,n-1);
// int right=findAns(m-1,n);

// return left+right;
// }

// int main(){

// int m,n;
// cin>>m>>n;
// cout<<findAns(m-1,n-1);
//     return 0;
// }




//MEMOIZATION
// T.C=O(m*n)
// S.C=O((m-1)+(n-1))+O(n*m)

// int findAns(int m,int n,vector<vector<int>>&dp){
// if(m==0 && n==0){
// 	return 1;
// }
// if(m<0 || n<0){
// 	return 0;
// }
// if(dp[m][n]!=-1)return dp[m][n];

// int left=findAns(m,n-1,dp);
// int right=findAns(m-1,n,dp);

// return dp[m][n]=left+right;
// }

// int main(){
// int m,n;
// cin>>m>>n;

// vector<vector<int>>dp(m,vector<int>(n,-1));

// cout<<findAns(m-1,n-1,dp);
//     return 0;
// }


// Tabulation
// T.C=O(m*n)
// S.C=O(m*n)


int findAns(int m,int n,vector<vector<int>>&dp){
dp[0][0]=1;

for(int i=0;i<=m;i++){
	for(int j=0;j<=n;j++){
		if(i==0 && j==0)continue;
		int top=0;int right=0;
		if(i>0){
			top=dp[i-1][j];
		}
		if(j>0){
			right=dp[i][j-1];
		}
		dp[i][j]=top+right;
	}
}
	return dp[m][n];

}
int main(){

int m,n;
cin>>m>>n;

vector<vector<int>>dp(m,vector<int>(n,-1));

cout<<findAns(m-1,n-1,dp);
    return 0;
}