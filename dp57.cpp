// 983. Minimum Cost For Tickets
// T.C => O(N × 396)


class Solution {
public:

    int findAns(vector<int>& days, vector<int>& costs,int i,int totaldays,vector<vector<int>>& dp){
        if(i>=days.size()){
            return 0;
        }

        if(dp[i][totaldays]!=-1){
            return dp[i][totaldays];
        }

        if(totaldays>=days[i]){
            return dp[i][totaldays]= findAns(days,costs,i+1,totaldays,dp);
        }
        else{
            int one=costs[0]+findAns(days,costs,i+1,days[i]+1-1,dp);
            int seven=costs[1]+findAns(days,costs,i+1,days[i]+7-1,dp);
            int thirty=costs[2]+findAns(days,costs,i+1,days[i]+30-1,dp);
            return dp[i][totaldays]= min(one,min(seven,thirty));
        }

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>>dp(n+1,vector<int>(396,-1));
        // ye 366 days the hamne ye case liya hai ki agr last index 365 hai and uspe hamne +30 
        // days wli call kri toh fir wo next call me 395 ko check krega 

        return findAns(days,costs,0,0,dp);
    }
};