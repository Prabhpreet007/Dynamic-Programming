// Unbounded Knapsack(CN)


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// T.C = exponential
// S.C = O(W)


// int findAns(int i,int wt,vector<int> &profit, vector<int> &weight,int sum){
//     if(wt==0)return sum;
//     if(i==0){
//         if(weight[0]<=wt){
            
//             int multi=0;
//             if(wt%weight[0]==0){
//                 multi=wt/weight[0];
//             }
//             return sum+(profit[i]*multi);
//         }
//         else{
//             return 0;
//         }
//     }

//     int take=0;
//     if(weight[i]<=wt){
//         take=findAns(i,wt-weight[i],profit,weight,sum+profit[i]);
//     }
//     int notTake=findAns(i-1,wt,profit,weight,sum);

//     return max(take,notTake);
// }

// int main(){
// int n,w;
// cin>>n>>w;
// vector<int>profit(n),weight(n);
// for(int i=0;i<n;i++){
//     cin>>profit[i];
// }
// for(int i=0;i<n;i++){
//     cin>>weight[i];
// }

// int sum=0;
//     cout<<findAns(n-1,w,profit,weight,sum);

// }

// T.C = O(w) in worst case
// S.C = O(n*w) + O(W)


// int findAns(int i,int wt,vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
    
//     if(i==0){            
//             return (profit[0]*(wt/weight[0]));
        
//     }

//     if(dp[i][wt]!=-1){
//         return dp[i][wt];
//     }

//     int take=0;
//     if(weight[i]<=wt){
//         take=profit[i]+findAns(i,wt-weight[i],profit,weight,dp);
//     }
//     int notTake=0+findAns(i-1,wt,profit,weight,dp);

//     return dp[i][wt]=max(take,notTake);
// }

// int main(){

// int n,w;
// cin>>n>>w;
// vector<int>profit(n),weight(n);
// for(int i=0;i<n;i++){
//     cin>>profit[i];
// }
// for(int i=0;i<n;i++){
//     cin>>weight[i];
// }

//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//     cout<< findAns(n-1,w,profit,weight,dp);

// }


// TABULATION
// T.C = O(w) in worst case
// S.C = O(n*w)+O(W)


int findAns(int wt,vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){


    for(int i=0;i<=wt;i++){
        dp[0][i]=profit[0]*(i/weight[0]);
    }

    for(int i=1;i<profit.size();i++){
        for(int j=0;j<=wt;j++){
            int take=0;
            if(weight[i]<=j){
                take=profit[i]+dp[i][j-weight[i]];
            }
            int notTake=0+dp[i-1][j];

            dp[i][j]=max(take,notTake);
        }
    }
    return dp[profit.size()-1][wt];

}

int main(){

int n,w;
cin>>n>>w;
vector<int>profit(n),weight(n);
for(int i=0;i<n;i++){
    cin>>profit[i];
}
for(int i=0;i<n;i++){
    cin>>weight[i];
}

    vector<vector<int>>dp(n,vector<int>(w+1,0));
    cout<<findAns(w,profit,weight,dp);

}