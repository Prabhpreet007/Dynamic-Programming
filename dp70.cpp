// 329. Longest Increasing Path in a Matrix


class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    int DFS(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){
        if(dp[i][j]!=0)return dp[i][j];

        int maxi=1;

        for(int ind=0;ind<4;ind++){
            int newr=dx[ind]+i;
            int newc=dy[ind]+j;
            if(newr>=0 && newc>=0 && newr<grid.size() && newc<grid[0].size() && grid[newr][newc]>grid[i][j]){
                maxi=max(maxi,1+DFS(grid,dp,newr,newc));
            }
        }

        return dp[i][j]=maxi;

    }

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        int ans=1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,DFS(matrix,dp,i,j));
            }
        }
        return ans;
    }
};