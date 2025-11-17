// 72. Edit Distance(L.C && C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

//RECURSIVE
// T.C = O()
// S.C = O()
    //     int findAns(string& w1,string& w2,int i,int j ){
    //     if(i<0 ){
    //         return j+1;
    //     }
    //     if(j<0 ){
    //         return i+1;
    //     }

    //     int ans=0;

    //     if(w1[i]==w2[j]){
            
    //         return 0+findAns(w1,w2,i-1,j-1);
    //     }
    //     else{
    //         int op1=1+findAns(w1,w2,i-1,j);
    //         int op2=1+findAns(w1,w2,i,j-1);
    //         int op3=1+findAns(w1,w2,i-1,j-1);
    //         return min(op1,min(op2,op3));
    //     }
    // }


// int main(){
// string word1,word2;
// cin>>word1>>word2;
//     int n=word1.length();
//     int m=word2.length();
//     int ans=findAns(word1,word2,n-1,m-1);
//     cout<< ans;

//     return 0;
// }

//MEMOIZATION
// T.C = O()
// S.C = O()

//     int findAns(string& w1,string& w2,int i,int j,vector<vector<int>>&dp){
//         if(i<0 ){
//             return j+1;
//         }
//         if(j<0 ){
//             return i+1;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];

//         if(w1[i]==w2[j]){
            
//             return dp[i][j]= 0+findAns(w1,w2,i-1,j-1,dp);
//         }
//         else{
//             //insert
//             int op1=1+findAns(w1,w2,i-1,j,dp);
//             //remove
//             int op2=1+findAns(w1,w2,i,j-1,dp);
//             //replace
//             int op3=1+findAns(w1,w2,i-1,j-1,dp);
//             return dp[i][j]= min(op1,min(op2,op3));
//         }
//     }

// int main(){
//     string word1,word2;
//     cin>>word1>>word2;
//     int n=word1.length();
//     int m=word2.length();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     int ans=findAns(word1,word2,n-1,m-1,dp);
// cout<< ans;

//     return 0;
// }


//MEMOIZATION WITH 1 BASED INDEXING
// T.C = O()
// S.C = O()

//         int findAns(string& w1,string& w2,int i,int j,vector<vector<int>>&dp){
//         if(i==0 ){
//             //yaha only j return hoga as it is 1 based indexing
//             return j;
//         }
//         if(j==0 ){
//             //yaha only i return hoga as it is 1 based indexing
//             return i;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];

//         if(w1[i-1]==w2[j-1]){
            
//             return dp[i][j]= 0+findAns(w1,w2,i-1,j-1,dp);
//         }
//         else{
//             //insert
//             int op1=1+findAns(w1,w2,i-1,j,dp);
//             //remove
//             int op2=1+findAns(w1,w2,i,j-1,dp);
//             //replace
//             int op3=1+findAns(w1,w2,i-1,j-1,dp);
//             return dp[i][j]= min(op1,min(op2,op3));
//         }
//     }


//     int main(){
//     string word1,word2;
//     cin>>word1>>word2;
//     int n=word1.length();
//     int m=word2.length();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     int ans=findAns(word1,word2,n,m,dp);
//     cout<< ans;

//     return 0;
// }


//TABULATION

    int main() {

        string word1,word2;
        cin>>word1>>word2;
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(word1[i-1]==word2[j-1]){
            
                    dp[i][j]= 0+dp[i-1][j-1];
        }
        else{
            //insert
            int op1=1+dp[i-1][j];
            //remove
            int op2=1+dp[i][j-1];
            //replace
            int op3=1+dp[i-1][j-1];
                dp[i][j]= min(op1,min(op2,op3));
        }
            }
        }
        cout<< dp[n][m];
    }