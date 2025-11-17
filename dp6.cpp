// 2-D dp starts from here
//  Ninja’s Training (CODING NINJAS)

#include<iostream>
#include<vector>
using namespace std;

// // ****RECURSIVE SOLN********

// int findAns(int days,int last,vector<vector<int>> &points){
//     if(days==0){
//         int maxi=0;
//         for(int i=0;i<3;i++){
//             if(i!=last){
//                 maxi=max(maxi,points[0][i]);
//             }
//         }
//         return maxi;
//     }

//     int finalMax=0;

//     for(int i=0;i<3;i++){
//         if(i!=last){
//             int ans=findAns(days-1,i,points)+points[days][i];
//             finalMax=max(finalMax,ans);
//         }
//     }
//     return finalMax;

// }

// int main(){

// int n;
// cin>>n;
// vector<vector<int>>points;
// for(int i=0;i<n;i++){
//     vector<int> x;
//     for(int j=0;j<3;j++){
//         int a;
//         cin>>a;
//         x.push_back(a);
//     }
//     points.push_back(x);
// }

//     cout<<findAns(n-1,3,points);

//     return 0;
// }




// MEMOIZATION
// TC = O(n*4)*3
// SC = O(n)+O(n*4)

int findAns(int days,int last,vector<vector<int>> &points,vector<vector<int>>&dp){
    if(days==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }

    if(dp[days][last]!=-1){
        return dp[days][last];
    }

    int finalMax=0;

    for(int i=0;i<3;i++){
        if(i!=last){
            int ans=findAns(days-1,i,points,dp)+points[days][i];
            finalMax=max(finalMax,ans);
        }
    }
    return dp[days][last]=finalMax;

}

int main(){

int n;
cin>>n;
vector<vector<int>>points;
for(int i=0;i<n;i++){
    vector<int> x;
    for(int j=0;j<3;j++){
        int a;
        cin>>a;
        x.push_back(a);
    }
    points.push_back(x);
}

vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<findAns(n-1,3,points,dp);

    return 0;
}