// Array partition with minimum difference (CODING NINJAS)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//T.C=O(n*(sum of all elements of given array))
//S.C=O(n*(sum of all elements of given array))

int main(){
int n;
cin>>n;
vector<int> arr(n);

for(int i=0;i<n;i++){
cin>>arr[i];
}


int sum=0;
for(int i=0;i<n;i++){
	sum+=arr[i];
}
vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));


for(int i=0;i<n;i++){
	dp[i][0]=true;
}

dp[0][arr[0]]=true;

for(int i=1;i<n;i++){
	for(int target=1;target<=sum;target++){
		bool notTake=dp[i-1][target];
		bool take=false;
		if(arr[i]<=target){
			take=dp[i-1][target-arr[i]];
		}
		dp[i][target]=notTake||take;
	}
}


int mini=INT_MAX;
for(int i=0;i<=sum;i++){
	if(dp[n-1][i]!=false){
		int a=i;
		int b=sum-i;
		mini=min(abs(a-b),mini);
	}
}
cout<<mini;
    return 0;
}