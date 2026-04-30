//Count Partitions With Given Difference(CODING NINJAS)
// GOOD QUESTION




// 1.  S1 - S2 = D
// 2.  S1 + S2 = totalSum

// from eq 1    3.  S1=D+S2
// put 3 in 2   4.  D+S2+S2=totalSum


// from 4.
// 2*S2 = totalSum-D
// S2=(totalSum-D)/2
// target = (totalSum-D)/2
// target can't be odd kyuki /2 hai and array me int hai 

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int mod=(int)(1e9+7);

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0){
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target==arr[0]) return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];


    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken)%mod;
}

int findWays(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return findWaysUtil(n - 1, k, num, dp);
}

int main(){


int n,d;
cin>>n>>d;

vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];

int total=0;
    for(auto i:arr)total+=i;

    if(total-d<0 || (total-d)%2!=0)return false;

    cout<< findWays(arr,(total-d)/2);
    return 0;
}