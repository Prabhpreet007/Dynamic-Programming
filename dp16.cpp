//Count Subsets with Sum K (coding ninjas)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


int findAns(vector<int>& arr, int& k,int sum,int i,int& count){
	if(sum==k){
		count++;
		return 1;
	}
	if(sum>k){
		return 0;
	}
	if(i>=arr.size()){
		return 0;
	}

	//take
	int take=findAns(arr,k,sum+arr[i],i+1,count);

	//not take
	int notTake=findAns(arr,k,sum,i+1,count);
	return take+notTake;
}

int main(){
int n;
int k;
cin>>n>>k;

vector<int>arr(n);

for(int i=0;i<n;i++){
    cin>>arr[i];
}

int sum=0;
int i=0;
int count=0;
cout<<findAns(arr,k,sum,i,count);
    return 0;
}
