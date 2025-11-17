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








// second approach
// O(n × total_sum)




int solve(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {

    if (target == 0) return 1;  // Subset with sum 0 is always possible

    if (index == 0) return arr[0] == target;  // Base case: only possible if target equals arr[0]

    

    if (dp[index][target] != -1) return dp[index][target];

    

    bool not_take = solve(index - 1, target, arr, dp);

    bool take = false;

    if (arr[index] <= target) take = solve(index - 1, target - arr[index], arr, dp);
    

    dp[index][target] = take || not_take;

    return dp[index][target];

}

int minSubsetSumDifference(vector<int>& arr, int n)
{
int total_sum = accumulate(arr.begin(), arr.end(), 0);

    int target = total_sum / 2;

 

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    

 

    int ans = INT_MAX;

    for (int s1 = 0; s1 <=target; s1++) {

      if (solve(n - 1, s1, arr, dp)) {

        
        int s2 = total_sum - s1;

        ans = min(ans, abs(s2 - s1));

      }

    }

 

    return ans;


}
