//   132. Palindrome Partitioning II(C.N & L.C)


// Memoization
// T.C=O(n^3)
// S.C=O(n)+O(n)


// bool isPalindrome(int i,int j,string& str){
//     while(i<j){
//         if(str[i]!=str[j]){
//             return false;
//         }
//         else{
//             i++;
//             j--;
//         }
//     }
//     return true;
// }

// int findAns(int i,int &n,string &str,vector<int>& dp){
//     if(i==n)return 0;
//     if(dp[i]!=-1)return dp[i];

//     int mini=INT_MAX;

//     for(int j=i;j<n;j++){
//         if(isPalindrome(i,j,str)){
//             int temp=1+findAns(j+1,n,str,dp);
//             mini=min(mini,temp);
//         }
//     }
//     return dp[i]= mini;

// }

//     int minCut(string str) {
//         int n=str.length();
//         vector<int>dp(n,-1);
//         return findAns(0,n,str,dp)-1;
//     }



// Tabulation
// T.C=O(n^3)
// S.C=O(n)

    int minCut(string str) {
        int n=str.length();
        vector<int>dp(n+1,0);
        // return findAns(0,n,str,dp)-1;

        for(int i=n-1;i>=0;i--){
                int mini=INT_MAX;

                for(int j=i;j<n;j++){
                if(isPalindrome(i,j,str)){
                    int temp=1+dp[j+1];
                    mini=min(mini,temp);
                }
            }
            dp[i]= mini;
        }
        return dp[0]-1;
        
    }