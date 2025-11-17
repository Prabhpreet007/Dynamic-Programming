// 1043. Partition Array for Maximum Sum(C.N & L.C)

//RECURSIVE SOLUTION

    // int f(int ind,vector<int>&arr,int k){
    //     if(ind==arr.size())return 0;

    //     int len=0;
    //     int maxi=INT_MIN;
    //     int maxAns=INT_MIN;

    //     int n=arr.size();
    //     for(int i=ind;i< min(n,ind+k);i++){
    //         len++;
    //         maxi=max(maxi,arr[i]);
    //         int sum=(len*maxi)+f(i+1,arr,k);
    //         maxAns=max(maxAns,sum);
    //     }
    //     return maxAns;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     return f(0,arr,k);
    // }


// MEMOIZATION

// t.c= O(n*k)


    //     int f(int ind,vector<int>&arr,int k,vector<int>& dp){
    //     if(ind==arr.size())return 0;

    //     if(dp[ind]!=-1)return dp[ind];

    //     int len=0;
    //     int maxi=INT_MIN;
    //     int maxAns=INT_MIN;

    //     int n=arr.size();
    //     for(int i=ind;i< min(n,ind+k);i++){
    //         len++;
    //         maxi=max(maxi,arr[i]);
    //         int sum=(len*maxi)+f(i+1,arr,k,dp);
    //         maxAns=max(maxAns,sum);
    //     }
    //     return dp[ind]=maxAns;
    // }

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     vector<int>dp (arr.size(),-1);

    //     return f(0,arr,k,dp);
    // }


    // TABULATION

    