// Longest Common Substring(CN)
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;



int main(){

string str1,str2;
cin>>str1>>str2;
int n=str1.length();
int m=str2.length();

int ans=0;
vector<vector<int>>dp(n+1,vector<int>(m+1,0));

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(str1[i-1]==str2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            ans=max(ans,dp[i][j]);
        }
        else{
            dp[i][j]=0;
        }
    }
}
cout<< ans;

    return 0;
}