//  Triangle (CODING NINJAS)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


//RECURSIVE SOLUTION 

// T.C=O(2^N)
// S.C=O(N) STACK SPACE

// int findAns(int i,int j,vector<vector<int>>& triangle){
// if(i==triangle.size()-1){
// 	return triangle[i][j];
// }
// int mini=INT_MAX;
// int down=findAns(i+1,j,triangle)+triangle[i][j];
// int rightdown=findAns(i+1,j+1,triangle)+triangle[i][j];
// mini=min(down,rightdown);
// return mini;

// }

// int main(){
// int n;
// cin>>n;
// vector<vector<int>>triangle(n);
// for(int i=0;i<n;i++){
//     vector<int>p(i+1);
//     for(int j=0;j<=i;j++){
//         cin>>p[j];
//     }
//     triangle[i]=p;
// }
// cout<<findAns(0,0,triangle);

//     return 0;
// } 



//MEMOIZATION

// T.C=O(N^N)
// S.C=O(N)+o(N*N) STACK SPACE&DP ARRAY

// int findAns(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
// if(i==triangle.size()-1){
// 	return triangle[i][j];
// }

// if(dp[i][j]!=-1)return dp[i][j];
// int mini=INT_MAX;
// int down=findAns(i+1,j,triangle,dp)+triangle[i][j];
// int rightdown=findAns(i+1,j+1,triangle,dp)+triangle[i][j];
// mini=min(down,rightdown);
// return dp[i][j]=mini;

// }



// int main(){
// int n;
// cin>>n;
// vector<vector<int>>triangle(n);
// for(int i=0;i<n;i++){
//     vector<int>p(i+1);
//     for(int j=0;j<=i;j++){
//         cin>>p[j];
//     }
//     triangle[i]=p;
// }
//     vector<vector<int>>dp(n);
// 	for(int i=0;i<n;i++){
// 		dp[i]=vector<int>(i+1,-1);
// 	}
// cout<<findAns(0,0,triangle,dp);

//     return 0;
// } 



//TABULATION
// T.C=O(N*N)
// S.C=O(N*N) ONLY DP ARRAY

int findAns(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
int n=triangle.size();
for(int i=0;i<n;i++){
	dp[n-1][i]=triangle[n-1][i];
}
if(n==1){
	return dp[0][0];
}
for(int i=n-2;i>=0;i--){
	for(int j=0;j<i+1;j++){
		int down=dp[i+1][j]+triangle[i][j];
		int rightdown=dp[i+1][j+1]+triangle[i][j];
		dp[i][j]=min(down,rightdown);
	}
}

return dp[0][0];

}


int main(){
int n;
cin>>n;
vector<vector<int>>triangle(n);
for(int i=0;i<n;i++){
    vector<int>p(i+1);
    for(int j=0;j<=i;j++){
        cin>>p[j];
    }
    triangle[i]=p;
}
    vector<vector<int>>dp(n);
	for(int i=0;i<n;i++){
		dp[i]=vector<int>(i+1,-1);
	}
cout<<findAns(0,0,triangle,dp);

    return 0;
} 