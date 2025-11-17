// Longest Palindromic Subsequence(CN)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
    int findAns(int i1,int i2,string &s1, string &s2,vector<vector<int>>&dp){

        for(int i=0;i<=i1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=i2;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=i1;i++){
            for(int j=1;j<=i2;j++){
                if(s1[i-1]==s2[j-1]){
                     dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                     dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[i1][i2];


    }


int main(){

string text1,text2;
cin>>text1>>text2;
int t1=text1.length();
        int t2=text2.length();
        vector<vector<int>>dp(t1+1,vector<int>(t2+1,0));
        cout<< findAns(t1,t2,text1,text2,dp);
    return 0;
}