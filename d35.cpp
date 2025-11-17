// 121. Best Time to Buy and Sell Stock(L.C & C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

int n;
cin>>n;

vector<int> prices(n);
for(int i=0;i<n;i++){
    cin>>prices[i];
}

        int mini=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            int diff=prices[i]-mini;
            ans=max(ans,diff);
            mini=min(mini,prices[i]);
        }
        
    cout<< ans;

    return 0;
}