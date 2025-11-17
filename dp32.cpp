// 115. Distinct Subsequences (L.C)
// Distinct Subsequences (C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

//RECURSIVE SOLN
//T.C=O(2^n + 2^m)
//S.C=o(n)

//     int findAns(string s,string t,int n,int m){
//         if(m<0){
//             return 1;
//         }
//         if(n<0){
//             return 0;
//         }

//         int a=0;
//         int b=0;
//         if(s[n]==t[m]){
//             return findAns(s,t,n-1,m-1)+findAns(s,t,n-1,m);
//         }
//         else{
//             return findAns(s,t,n-1,m);
//         }
        
//     }

// int main(){


// string s,t;
// cin>>s>>t;
//         int n=s.length();
//         int m=t.length();
//         cout<<findAns(s,t,n-1,m-1);

// return 0;
// }


// MEMOIZATION
//T.C=O(n * m)
//S.C=O(n*m)+O(n+m)

//     int findAns(string &s,string &t,int n,int m,vector<vector<int>>&dp){
//         if(m<0){
//             return 1;
//         }
//         if(n<0){
//             return 0;
//         }
//         if(dp[n][m]!=-1){
//             return dp[n][m];
//         }

//         int a=0;
//         int b=0;
//         if(s[n]==t[m]){
//             return dp[n][m]= findAns(s,t,n-1,m-1,dp)+findAns(s,t,n-1,m,dp);
//         }
//         else{
//             return dp[n][m]=findAns(s,t,n-1,m,dp);
//         }

//     }

// int main(){

// string s,t;
// cin>>s>>t;
//         int n=s.length();
//         int m=t.length();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         cout<< findAns(s,t,n-1,m-1,dp);
// return 0;
// }


//As the base case is for <0 that we can't express in dp array so convert this into 1 based indexing solution 
//Memoization for 1 based indexing

//         int findAns(string &s,string &t,int n,int m,vector<vector<int>>&dp){
//         if(m==0){
//             return 1;
//         }
//         if(n==0){
//             return 0;
//         }

//         if(dp[n][m]!=-1){
//             return dp[n][m];
//         }

//         int a=0;
//         int b=0;
//         if(s[n-1]==t[m-1]){
//             return dp[n][m]= findAns(s,t,n-1,m-1,dp)+findAns(s,t,n-1,m,dp);
//         }
//         else{
//             return dp[n][m]=findAns(s,t,n-1,m,dp);
//         }

//     }

// int main(){

//     string s,t;
//     cin>>s>>t;
//             int n=s.length();
//             int m=t.length();
//             vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//             cout<< findAns(s,t,n,m,dp);
//             return 0;
// }

//TABULATION
//T.C=O(n*m)
//S.C=O(n*m)

int findAns(string &s,string &t,int n,int m,vector<vector<double>>&dp){

        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];

    }

int main(){

    string s,t;
    cin>>s>>t;
            int n=s.length();
            int m=t.length();
            vector<vector<double>>dp(n+1,vector<double>(m+1,0));
            cout<< (int)findAns(s,t,n,m,dp);
            return 0;
}