// 714. Best Time to Buy and Sell Stock with Transaction Fee

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

    int findAns(int i,int check,vector<int>& prices,int &fee,vector<vector<int>>& dp){

        if(i==prices.size()){
            return 0;
        }

        if(dp[i][check]!=-1){
            return dp[i][check];
        }
        int ans=0;
        if(check==1){
            ans=max(-prices[i]+findAns(i+1,0,prices,fee,dp),0+findAns(i+1,1,prices,fee,dp));
        }
        
        else{
            ans=max(+prices[i]-fee+findAns(i+1,1,prices,fee,dp),0+findAns(i+1,0,prices,fee,dp));
        }
        return dp[i][check]= ans;
    }

int main(){
int n,fee;
cin>>n>>fee;
vector<int> prices(n);
for(int i=0;i<n;i++){
    cin>>prices[i];
}

    int i=0;
    int check=1;
vector<vector<int>>dp (n,vector<int>(2,-1));
    cout<< findAns(i,check,prices,fee,dp);

}