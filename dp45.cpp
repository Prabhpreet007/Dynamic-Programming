// 1048. Longest String Chain(L.C & C.N)

// T.C=O(n^2*LengthofTheWord)

    bool checkCompare(string &s1,string &s2){
        if(s1.size()!=s2.size()+1)return false;

        int i=0,j=0;
        while(s1.length()>i){
            if(j<s2.length() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.length() && j==s2.length())return true;
        else{
            return false;
        }
    }

    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);

        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkCompare(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }