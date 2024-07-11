// 309. Best Time to Buy and Sell Stock with Cooldown(L.C & C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

// int findAns(int i,int check,vector<int>& prices){

//         if(i>=prices.size()){
//             return 0;
//         }

//         int ans=0;
//         if(check==1){
//             ans=max(-prices[i]+findAns(i+1,0,prices),0+findAns(i+1,1,prices));
//         }
        
//         else{
//             ans=max(+prices[i]+findAns(i+2,1,prices),0+findAns(i+1,0,prices));
//         }
//         return ans;
//     }

// int main(){
// int n;
// cin>>n;
// vector<int> prices(n);
// for(int i=0;i<n;i++){
//     cin>>prices[i];
// }

//     int i=0;
//     int check=1;
//     cout<< findAns(i,check,prices);

//     return 0;
// }


//     int findAns(int i,int check,vector<int>& prices,vector<vector<int>>&dp){

//         if(i>=prices.size()){
//             return 0;
//         }

//         if(dp[i][check]!=-1){
//             return dp[i][check];
//         }

//         int ans=0;
//         if(check==1){
//             ans=max(-prices[i]+findAns(i+1,0,prices,dp),0+findAns(i+1,1,prices,dp));
//         }

//         else{
//             ans=max(+prices[i]+findAns(i+2,1,prices,dp),0+findAns(i+1,0,prices,dp));
//         }
//         return dp[i][check]=ans;
//     }

// int main(){
// int n;
// cin>>n;
// vector<int> prices(n);
// for(int i=0;i<n;i++){
//     cin>>prices[i];
// }

//     int i=0;
//     int check=1;
// vector<vector<int>>dp (n,vector<int>(2,-1));
//     cout<< findAns(i,check,prices,dp);
//     return 0;
// }


int main(){
int n;
cin>>n;
vector<int> prices(n);
for(int i=0;i<n;i++){
    cin>>prices[i];
}

int i=0;
int check=1;

        vector<vector<int>>dp (n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int check=0;check<2;check++){
                int ans=0;
                if(check==1){
                    ans=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }

                else{
                    ans=max(+prices[i]+dp[i+2][1],0+dp[i+1][0]);
                }
                dp[i][check]=ans;
            }
        }
        cout<< dp[0][check];

    return 0;
}


// T.C = O(N)

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        int check=1;

        vector<vector<int>>dp (n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
                    dp[i][1]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                
                    dp[i][0]=max(+prices[i]+dp[i+2][1],0+dp[i+1][0]);
            }
        
        return dp[0][check];
    }