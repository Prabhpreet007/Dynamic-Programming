// 1312. Minimum Insertion Steps to Make a String Palindrome(LC)
//  Minimum insertions to make a string palindrome(CN)


#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

int findAns(string &s1,string &s2){
	int n=s1.length();
	int m=s2.length();

	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int main(){
string str;
cin>>str;
	int n=str.length();
	string rev_str=str;
	reverse(rev_str.begin(),rev_str.end());
	cout<< n-findAns(str,rev_str);

    return 0;
}