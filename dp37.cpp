// 123. Best Time to Buy and Sell Stock III (L.C & C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

//RECURSIVE
//T.C=EXPONENTIAL
//S.C=O(N)

//     int findAns(int i,int check,int limit,vector<int>&prices){
//         if(limit==0){
//             return 0;   
//         }
//         if(i>=prices.size()){
//             return 0;
//         }

//         int profit=0;
//         if(check==1){
//             profit=max(-prices[i]+findAns(i+1,0,limit,prices),0+findAns(i+1,1,limit,prices));
//         }
//         else{
//             profit=max(+prices[i]+findAns(i+1,1,limit-1,prices),0+findAns(i+1,0,limit,prices));
//         }
//         return profit;
//     }

// int main(){
// int n;
// cin>>n;
// vector<int>prices(n);
// for(int i=0;i<n;i++){
//     cin>>prices[i];
// }
//     int check=1;
//     int limit=2;
//     cout<<findAns(0,check,limit,prices);

//     return 0;
// }



//MEMOIZATION
//T.C=O(N*2*3)
//S.C=O(N*2*3)+O(N)

//     int findAns(int i,int check,int limit,vector<int>&prices,vector<vector<vector<int>>> &dp){
//         if(limit==0){
//             return 0;   
//         }
//         if(i>=prices.size()){
//             return 0;
//         }

//         if(dp[i][check][limit]!=-1){
//             return dp[i][check][limit];
//         }

//         int profit=0;
//         if(check==1){
//             profit=max(-prices[i]+findAns(i+1,0,limit,prices,dp),0+findAns(i+1,1,limit,prices,dp));
//         }
//         else{
//             profit=max(+prices[i]+findAns(i+1,1,limit-1,prices,dp),0+findAns(i+1,0,limit,prices,dp));
//         }
//         return dp[i][check][limit]= profit;
//     }


//     int main(){
//     int n;
//     cin>>n;
//     vector<int>prices(n);
//     for(int i=0;i<n;i++){
//         cin>>prices[i];
//     }
//         int check=1;
//         int limit=2;
//         vector<vector<vector<int>>>dp (prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));

//         cout<<findAns(0,check,limit,prices,dp);

//         return 0;
// }



//TABULATION

//T.C=O(N*2*3)
//S.C=O(N*2*3)


// int main(){
//     int n;
//     cin>>n;
//     vector<int>prices(n);
//     for(int i=0;i<n;i++){
//         cin>>prices[i];
//     }

// int check=1;
//         int limit=2;

//         vector<vector<vector<int>>>dp (prices.size()+1,vector<vector<int>>(limit,vector<int>(3,0)));


//         for(int i=0;i<prices.size();i++){
//             for(int j=0;j<2;j++){
//                 dp[i][j][0]=0;
//             }
//         }

//         for(int i=0;i<2;i++){
//             for(int j=0;j<3;j++){
//                 dp[prices.size()][i][j]=0;
//             }
//         }

//         // we can skip these two base cases as everything is 0 previously

//         for(int i=n-1;i>=0;i--){
//             for(int check=0;check<2;check++){
//                 for(int limit=1;limit<3;limit++){
//                             int profit=0;
//                             if(check==1){
//                                 profit=max(-prices[i]+dp[i+1][0][limit],0+dp[i+1][1][limit]);
//                             }
//                             else{
//                                 profit=max(+prices[i]+dp[i+1][1][limit-1],0+dp[i+1][0][limit]);
//                             }
//                             dp[i][check][limit]= profit;
//                 }
//             }
//         }

//         cout<<dp[0][check][limit];
//     return 0;
// }




//SPACE OPTIMIZATION
//T.C=O(N*2*3)
//S.C=O(2*3)+O(2*3)


int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

int check=1;
        int limit=2;

        vector<vector<int>>next (2,vector<int>(3,0));
        vector<vector<int>>prev (2,vector<int>(3,0));

        for(int i=n-1;i>=0;i--){
            for(int check=0;check<2;check++){
                for(int limit=1;limit<3;limit++){
                            int profit=0;
                            if(check==1){
                                profit=max(-prices[i]+next[0][limit],0+next[1][limit]);
                            }
                            else{
                                profit=max(+prices[i]+next[1][limit-1],0+next[0][limit]);
                            }
                            prev[check][limit]= profit;
                }
            }
            next=prev;
        }

        cout<<next[check][limit];

    return 0;
}