// 44. Wildcard Matching(L.C & C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

    // bool findAns(string &s, string &p,int n,int m){

    //     if(n<0 && m<0){
    //         return true;
    //     }
    //     if(n<0 && m>=0){
    //         for(int i=0;i<=m;i++){
    //             if(p[i]!='*')return false;
    //         }
    //         return true;
            
    //     }

    //     if(n>=0 && m<0){
    //         return false;
    //     }

    //     if(s[n]==p[m] || p[m]=='?'){
    //         return findAns(s,p,n-1,m-1);
    //     }
    //     else if(p[m]=='*'){
    //         return findAns(s,p,n-1,m)||findAns(s,p,n,m-1);
    //     }
    //     else{
    //         return false;
    //     }
    // }

    // int main(){
    //     string s,p;
    //     cin>>s>>p;

    //     int n=s.length();
    //     int m=p.length();

    //     cout<<findAns(s,p,n-1,m-1);
    // }


//MEMOIZATION
// T.C=O(N*M)
// S.C=O(N*M)+O(N*M)


    // bool findAns(string &s, string &p,int n,int m,vector<vector<int>>& dp){

    //     if(n<0 && m<0){
    //         return true;
    //     }
    //     if(n<0 && m>=0){
    //         for(int i=0;i<=m;i++){
    //             if(p[i]!='*')return false;
    //         }
    //         return true;
            
    //     }
    //     if(n>=0 && m<0){
    //         return false;
    //     }


    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }

    //     if(s[n]==p[m] || p[m]=='?'){
    //         return dp[n][m]= findAns(s,p,n-1,m-1,dp);
    //     }

    //     else if(p[m]=='*'){
    //         return dp[n][m]=findAns(s,p,n-1,m,dp)||findAns(s,p,n,m-1,dp);
    //     }

    //     else{
    //         return dp[n][m]=false;
    //     }
    // }



    //     int main(){
    //     string s,p;
    //     cin>>s>>p;

    //     int n=s.length();
    //     int m=p.length();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));

    //     return findAns(s,p,n-1,m-1,dp);
    // }




    //MEMOIZATION WITH 1 BASED INDEXING

    //     bool findAns(string &s, string &p,int n,int m,vector<vector<int>>& dp){

    //     if(n==0 && m==0){
    //         return true;
    //     }
    //     if(n==0 && m>=1){
    //         for(int i=0;i<m;i++){
    //             //important
    //             //not <= in this as its 1 based indexing

    //             if(p[i]!='*')return false;
    //         }
    //         return true;
            
    //     }
    //     if(n>=1 && m==0){
    //         return false;
    //     }


    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }

    //     if(s[n-1]==p[m-1] || p[m-1]=='?'){
    //         return dp[n][m]= findAns(s,p,n-1,m-1,dp);
    //     }

    //     else if(p[m-1]=='*'){
    //         return dp[n][m]=findAns(s,p,n-1,m,dp)||findAns(s,p,n,m-1,dp);
    //     }

    //     else{
    //         return dp[n][m]=false;
    //     }
    // }


    // int main(){
    //     string s,p;
    //     cin>>s>>p;

    //     int n=s.length();
    //     int m=p.length();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    //     return findAns(s,p,n,m,dp);
    // } 


//TABULATION
