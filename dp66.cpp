// 1911. Maximum Alternating Subsequence Sum


class Solution {
public:

    long long findAns(vector<int>& nums,int i,int check,vector<vector<long long>>& dp){

        if(i>=nums.size())return 0;

        if(dp[i][check]!=-1)return dp[i][check];
        

        long long take;
        if(!check){
            take=nums[i]+findAns(nums,i+1,!check,dp);
        }
        else{
            take=-nums[i]+findAns(nums,i+1,!check,dp);
        }
        long long notTake=findAns(nums,i+1,check,dp);

        return dp[i][check] = max(take,notTake);

    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return findAns(nums,0,0,dp);//1 means even agr 1 hoga toh it means odd 
    }
};