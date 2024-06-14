// 3-D DP STARTS FROM HERE 

// Chocolate Pickup (CODING NINJAS)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


//RECURSIVE SOLUTION(ITS NOT WORKING IN VSCODE BUT WORKING IN GDB)
// TC = O(3^N + 3^M)   VERY BAD
// SC = O(N)


// int findAns(int i,int j1,int j2,vector<vector<int>> &grid){
// if(i==grid.size()-1){
//     if(j1==j2){
//         return grid[i][j1];
//     }
//     else{
//         return grid[i][j1]+grid[i][j2];
//     }
// }

// if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()){
//     return -1e9;
// }

// int maxi=-1e9;
// for(int dir1=-1;dir1<=1;dir1++){
//     for(int dir2=-1;dir2<=1;dir2++){
//         int value=0;
//         if(j1==j2){
//             value=grid[i][j1]+findAns(i+1,j1+dir1,j2+dir2,grid);
//         }
//         else{
//             value=grid[i][j1]+grid[i][j2]+findAns(i+1,j1+dir1,j2+dir2,grid);
//         }
//         maxi=max(maxi,value);
//     }
// }

// return maxi;

// }


// int main(){

// int r,c;
// cin>>r>>c;
// vector<vector<int>>grid(r,vector<int>(c));

// for(int i=0;i<r;i++){
//     for(int j=0;j<c;j++){
//         cin>>grid[i][j];
//     }
// }

// cout<<findAns(0,0,c-1,grid);

//     return 0;
// }


//MEMOIZATION
// TC = O(R*C*C)*9
// SC = O(R*C*C)+O(R)

int findAns(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){

//make sure to write this base case first
if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()){
    return -1e9;
}

if(i==grid.size()-1){
    if(j1==j2){
        return grid[i][j1];
    }
    else{
        return grid[i][j1]+grid[i][j2];
    }
}


    if (dp[i][j1][j2] != -1) {
        return dp[i][j1][j2];
    }

int maxi=INT_MIN;
for(int dir1=-1;dir1<=1;dir1++){
    for(int dir2=-1;dir2<=1;dir2++){
        int value=INT_MIN;
        if(j1==j2){
            value=grid[i][j1]+findAns(i+1,j1+dir1,j2+dir2,grid,dp);
        }
        else{
            value=grid[i][j1]+grid[i][j2]+findAns(i+1,j1+dir1,j2+dir2,grid,dp);
        }
        maxi=max(maxi,value);
    }
}

return dp[i][j1][j2]=maxi;
}

int main(){

int r,c;
cin>>r>>c;
vector<vector<int>>grid(r,vector<int>(c));

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>grid[i][j];
    }
}
vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    cout<<findAns(0,0,c-1,grid,dp);

    return 0;
}


