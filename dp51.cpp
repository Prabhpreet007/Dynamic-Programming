// Boolean Evaluation(C.N)

int mod=1e9;

int findAns(int i,int j,int isTrue,string & exp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==1){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }
    long long ways=0;
    for(int k=i+1;k<=j-1;k+=2){
        long long LT=(findAns(i,k-1,1,exp)%mod)%mod;
        long long LF=(findAns(i,k-1,0,exp)%mod)%mod;
        long long RT=(findAns(k+1,j,1,exp)%mod)%mod;
        long long RF=(findAns(k+1,j,0,exp)%mod)%mod;

        if(exp[k]=='&'){
            if(isTrue){
                ways=(ways+((LT*RT)%mod))%mod;
            }
            else{
                ways=(ways+((LT*RF)%mod)+((LF*RF)%mod)+((LF*RT)%mod))%mod;

            }
        }


        else if(exp[k]=='|'){
            if(isTrue){
                ways=(ways+((LT*RF)%mod)+((LT*RT)%mod)+((LF*RT)%mod))%mod;

            }
            else{
                ways=(ways+((LF*RF)%mod))%mod;
            }
        }


        else{
            if(isTrue){
                ways=(ways+((LT*RF)%mod)+((LF*RT)%mod))%mod;
            }
            else{
                ways=(ways+((LT*RT)%mod)+((LF*RF)%mod))%mod;
            }
        }


    }
    return ways;
}

int evaluateExp(string & exp) {
    return findAns(0,exp.size()-1,1,exp);
}



// memoization

// T.C = O(N*N*2) * N(ye last wla N internal K for loop wla hai)
        

int mod=1e9+7;
int findAns(int i,int j,int isTrue,string & exp,vector<vector<vector<int>>>& dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==1){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }

    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    long long ways=0;
    for(int k=i+1;k<=j-1;k+=2){
        long long LT=(findAns(i,k-1,1,exp,dp)%mod)%mod;
        long long LF=(findAns(i,k-1,0,exp,dp)%mod)%mod;
        long long RT=(findAns(k+1,j,1,exp,dp)%mod)%mod;
        long long RF=(findAns(k+1,j,0,exp,dp)%mod)%mod;

        if(exp[k]=='&'){
            if(isTrue){
                ways=(ways+((LT*RT)%mod))%mod;
            }
            else{
                ways=(ways+((LT*RF)%mod)+((LF*RF)%mod)+((LF*RT)%mod))%mod;

            }
        }
        else if(exp[k]=='|'){
            if(isTrue){
                ways=(ways+((LT*RF)%mod)+((LT*RT)%mod)+((LF*RT)%mod))%mod;

            }
            else{
                ways=(ways+((LF*RF)%mod))%mod;
            }
        }
        else{
            if(isTrue){
                ways=(ways+((LT*RF)%mod)+((LF*RT)%mod))%mod;
            }
            else{
                ways=(ways+((LT*RT)%mod)+((LF*RF)%mod))%mod;
            }
        }
    }
    return dp[i][j][isTrue]= ways;
}

int evaluateExp(string & exp) {
    int n=exp.length();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return findAns(0,exp.size()-1,1,exp,dp);
}


