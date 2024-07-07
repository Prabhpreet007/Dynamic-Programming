// 122. Best Time to Buy and Sell Stock II(L.C & C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

//ITERATIVE SOLN
// TC=O(N)
// SC=O(N)

// int main(){
// int n;
// cin>>n;
// vector<int>prices(n);
// for(int i=0;i<n;i++){
//     cin>>prices[i];
// }

//    int profit=0;
//         for(int i=1;i<=prices.size()-1;i++){
        
//             if(prices[i]>prices[i-1]){
//                 profit+=prices[i]-prices[i-1];
//             }
         
//         }
//         cout<<profit;
//     return 0;
// }


//RECURSIVE
// TC=O(2^n)
// SC=O(n) 

    // int findAns(int i,int check,vector<int>& prices){
    //     if(i==prices.size()){
    //         return 0;
    //     }

    //     int profit=0;

    //     if(check==1){
    //         profit=max(-prices[i]+findAns(i+1,0,prices),0+findAns(i+1,1,prices));
    //     }
    //     else{
    //         profit=max(+prices[i]+findAns(i+1,1,prices),0+findAns(i+1,0,prices));
    //     }

    //     return profit;
    // }

    // int main(){

    //     int n;
    //     cin>>n;
    //     vector<int>prices(n);
    //     for(int i=0;i<n;i++){
    //         cin>>prices[i];
    //     }

    //     int i=0;
    //     int check=1;
    //     //1 means we can buy now and 0 means we can sell now
    //     cout<<findAns(i,check,prices);


    //     return 0;
    // }


//MEMOIZATION
// TC=O(N*2)
// SC=O(N*2)+O(N)


    //     int findAns(int i,int check,vector<int>& prices,vector<vector<int>>& dp){
    //     if(i==prices.size()){
    //         return 0;
    //     }

    //     if(dp[i][check]!=-1)return dp[i][check];

    //     int profit=0;

    //     if(check==1){
    //         profit=max(-prices[i]+findAns(i+1,0,prices,dp),0+findAns(i+1,1,prices,dp));
    //     }
    //     else{
    //         profit=max(+prices[i]+findAns(i+1,1,prices,dp),0+findAns(i+1,0,prices,dp));
    //     }

    //     return dp[i][check]=profit;
    // }

    // int main(){

    //     int n;
    //     cin>>n;
    //     vector<int>prices(n);
    //     for(int i=0;i<n;i++){
    //         cin>>prices[i];
    //     }

    //     int i=0;
    //     int check=1;
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     cout<< findAns(i,check,prices,dp);
    //     //1 means we can buy now and 0 means we can sell now


    //     return 0;
    // }



// TABULATION
// TC=O(N*2)
// SC=O(N*2)

    // int main(){
    //     int n;
    //     cin>>n;
    //     vector<int>prices(n);
    //     for(int i=0;i<n;i++){
    //         cin>>prices[i];
    //     }

    //     int i=0;
    //     int check=1;
    //     vector<vector<int>>dp(n+1,vector<int>(2,0));

    //     dp[n][0]=0;
    //     dp[n][1]=0;

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<2;j++){
    //             int profit=0;

    //             if(j==1){
    //                 profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
    //             }

    //             else{
    //                 profit=max(+prices[i]+dp[i+1][1],0+dp[i+1][0]);
    //             }

    //             dp[i][j]=profit;
    //         }
    //     }

    //     cout<< dp[0][1];
    //     return 0;
    // }



    int main() {

        int n;
        cin>>n;
        vector<int>prices(n);
        for(int i=0;i<n;i++){
            cin>>prices[i];
        }
        
        vector<int>next(2,0),prev(2,0);
        next[0]=0;
        next[1]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit=0;

                if(j==1){
                    profit=max(-prices[i]+next[0],0+next[1]);
                }
                else{
                    profit=max(+prices[i]+next[1],0+next[0]);
                }

                prev[j]=profit;
            }
            next=prev;
        }
        cout<<next[1];

        return 0;
    }