// similar question not in playlist
// 312. Burst Balloons(L.C)




// New Solution

class Solution {
public:

    int findAns(int i,int j,vector<int>&nums,vector<vector<int>>& dp){

        if(i>j)return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int steps=nums[i-1]*nums[k]*nums[j+1]+findAns(i,k-1,nums,dp)+findAns(k+1,j,nums,dp);
            if(steps>maxi)maxi=steps;
        }
        return dp[i][j]= maxi;
    
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        cout<<n-1<<endl;
        cout<<nums[n-1]<<endl;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findAns(1,nums.size()-2,nums,dp);
    }
};









// T.C=exponential
// S.C=O(n)
    int findAns(int i,int j,vector<int>&nums){

        if(i==j)return 0;

        int maxi=INT_MIN;
        for(int k=i;k<j;k++){
            int steps=nums[i-1]*nums[k]*nums[j]+findAns(i,k,nums)+findAns(k+1,j,nums);
            if(steps>maxi)maxi=steps;
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
                nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return findAns(1,nums.size()-1,nums);
    }


// MEMOIZATION
// T.C=O(N*N)*N
    //    I AND J EACH WILL HAVE N STATES SO N*N AND FOR THE REST N ITS FOR LOOP OF K
// S.C=O(N*N)+O(N)

    int findAns(int i,int j,vector<int>&nums,vector<vector<int>>& dp){

        if(i==j)return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int maxi=INT_MIN;
        for(int k=i;k<j;k++){
            int steps=nums[i-1]*nums[k]*nums[j]+findAns(i,k,nums,dp)+findAns(k+1,j,nums,dp);
            if(steps>maxi)maxi=steps;
        }
        return dp[i][j]= maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findAns(1,nums.size()-1,nums,dp);
    }



// Tabulation
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // return findAns(1,nums.size()-1,nums,dp);

        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n-1;j++){
                    int maxi=INT_MIN;
                    for(int k=i;k<j;k++){
                        int steps=nums[i-1]*nums[k]*nums[j]+dp[i][k]+dp[k+1][j];
                        if(steps>maxi)maxi=steps;
                    }
                    dp[i][j]=maxi;
            }
        }
        return dp[1][n-1];
    }