// 188. Best Time to Buy and Sell Stock IV(C.N & L.C)


#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;


// int findAns(int i,int check,int k,vector<int>& prices){
//         if(k==0){
//             return 0;
//         }
//         if(i>=prices.size()){
//             return 0;
//         }

//         int ans=0;
//         if(check==1){
//             ans=max(-prices[i]+findAns(i+1,0,k,prices),0+findAns(i+1,1,k,prices));
//         }
//         else{
//             ans=max(+prices[i]+findAns(i+1,1,k-1,prices),0+findAns(i+1,0,k,prices));
//         }
//         return ans;
//     }

// int main(){

// int n,k;
// cin>>n>>k;
// vector<int>prices(n);
// for(int i=0;i<n;i++){
//     cin>>prices[i];
// }

//     int i=0;
//     int check=1;
//     cout<<findAns(i,check,k,prices);

//     return 0;
// }



// int findAns(int i,int check,int k,vector<int>& prices,vector<vector<vector<int>>>&dp){
//         if(k==0){
//             return 0;
//         }
//         if(i>=prices.size()){
//             return 0;
//         }

//         if(dp[i][check][k]!=-1){
//             return dp[i][check][k];
//         }

//         int ans=0;
//         if(check==1){
//             ans=max(-prices[i]+findAns(i+1,0,k,prices,dp),0+findAns(i+1,1,k,prices,dp));
//         }
//         else{
//             ans=max(+prices[i]+findAns(i+1,1,k-1,prices,dp),0+findAns(i+1,0,k,prices,dp));
//         }
//         return dp[i][check][k]=ans;
//     }


// int main(){

// int n,k;
// cin>>n>>k;
// vector<int>prices(n);
// for(int i=0;i<n;i++){
//     cin>>prices[i];
// }

//     int i=0;
//     int check=1;
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
//     cout<< findAns(i,check,k,prices,dp);
//     return 0;
// }

int main(){

int n,k;
cin>>n>>k;
vector<int>prices(n);
for(int i=0;i<n;i++){
    cin>>prices[i];
}

int i=0;
        int check=1;
        int x=k;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));


    for(int i=n-1;i>=0;i--){
            for(int check=0;check<2;check++){
                for(int k=1;k<x+1;k++){
                    int ans=0;
                    if(check==1){
                        ans=max(-prices[i]+dp[i+1][0][k],0+dp[i+1][1][k]);
                    }
                    else{
                        ans=max(+prices[i]+dp[i+1][1][k-1],0+dp[i+1][0][k]);
                    }
                    dp[i][check][k]=ans;
                }
            }
        }
        cout<< dp[0][check][k];

}