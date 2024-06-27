// 1143. Longest Common Subsequence (L.C) and  Longest Common Subsequence (C.N)


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//RECURSIVE SOLN
//T.C=O((2^n)*(2^m))
//S.C=O(n+m)

    // int findAns(int i1,int i2,string s1, string s2){

    //     if(i1<0 || i2<0){
    //         return 0;
    //     }

    //     if(s1[i1]==s2[i2]){
    //         return (1+findAns(i1-1,i2-1,s1,s2));
    //     }
    //     else{
    //         return 0+max(findAns(i1-1,i2,s1,s2),findAns(i1,i2-1,s1,s2));
    //     }
    // }

    // int main(){
    //     string text1,text2;
    //     cin>>text1>>text2;

    //     int t1=text1.length();
    //     int t2=text2.length();
    //     cout<< findAns(t1-1,t2-1,text1,text2);

    //     return 0;
    // }


//MEMOIZATION
//T.C=O(n*m)
//S.C=O(n+m)+O(n*m)

    //     int findAns(int i1,int i2,string &s1, string &s2,vector<vector<int>>&dp){

    //     if(i1<0 || i2<0){
    //         return 0;
    //     }

    //     if(dp[i1][i2]!=-1){
    //         return dp[i1][i2];
    //     }

    //     if(s1[i1]==s2[i2]){
    //         return dp[i1][i2]= (1+findAns(i1-1,i2-1,s1,s2,dp));
    //     }
    //     else{
    //         return dp[i1][i2]=0+max(findAns(i1-1,i2,s1,s2,dp),findAns(i1,i2-1,s1,s2,dp));
    //     }
    // }

    //     int main(){
    //     string text1,text2;
    //     cin>>text1>>text2;

    //     int t1=text1.length();
    //     int t2=text2.length();
    //     vector<vector<int>>dp(t1+1,vector<int>(t2+1,-1));

    //     cout<< findAns(t1-1,t2-1,text1,text2,dp);

    //     return 0;
    // }


    //Memoization(after increasing index)

        //     int findAns(int i1,int i2,string &s1, string &s2,vector<vector<int>>&dp){

    //     if(i1==0 || i2==0){
    //         return 0;
    //     }

    //     if(dp[i1][i2]!=-1){
    //         return dp[i1][i2];
    //     }

    //     if(s1[i1-1]==s2[i2-1]){
    //         return dp[i1][i2]= (1+findAns(i1-1,i2-1,s1,s2,dp));
    //     }
    //     else{
    //         return dp[i1][i2]=0+max(findAns(i1-1,i2,s1,s2,dp),findAns(i1,i2-1,s1,s2,dp));
    //     }
    // }

    //     int main(){
    //     string text1,text2;
    //     cin>>text1>>text2;

    //     int t1=text1.length();
    //     int t2=text2.length();
    //     vector<vector<int>>dp(t1+1,vector<int>(t2+1,-1));

    //     cout<< findAns(t1,t2,text1,text2,dp);

    //     return 0;
    // }


//Tabulation

    //     int findAns(int i1,int i2,string &s1, string &s2,vector<vector<int>>&dp){

    //     for(int i=0;i<=i1;i++){
    //         dp[i][0]=0;
    //     }
    //     for(int j=0;j<=i2;j++){
    //         dp[0][j]=0;
    //     }

    //     for(int i=1;i<=i1;i++){
    //         for(int j=1;j<=i2;j++){
    //             if(s1[i-1]==s2[j-1]){
    //                  dp[i][j]= 1+dp[i-1][j-1];
    //             }
    //             else{
    //                  dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[i1][i2];
    // }


    // int main(){
    //     string text1,text2;
    //     cin>>text1>>text2;

    //     int t1=text1.length();
    //     int t2=text2.length();
    //     vector<vector<int>>dp(t1+1,vector<int>(t2+1,0));

    //     cout<< findAns(t1,t2,text1,text2,dp);
    //     // here pass 1+ index and uppr funcn me b 1- krna hai as we are increasing index

    //     return 0;
    // }

