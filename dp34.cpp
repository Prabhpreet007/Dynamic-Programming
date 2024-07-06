// 44. Wildcard Matching(L.C & C.N)

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

    bool findAns(string &s, string &p,int n,int m){

        if(n<0 && m<0){
            return true;
        }
        if(n<0 && m>=0){
            for(int i=0;i<=m;i++){
                if(p[i]!='*')return false;
            }
            return true;
            
        }

        if(n>=0 && m<0){
            return false;
        }

        if(s[n]==p[m] || p[m]=='?'){
            return findAns(s,p,n-1,m-1);
        }
        else if(p[m]=='*'){
            return findAns(s,p,n-1,m)||findAns(s,p,n,m-1);
        }
        else{
            return false;
        }
    }

    int main(){
        string s,p;
        cin>>s>>p;

        int n=s.length();
        int m=p.length();

        cout<<findAns(s,p,n-1,m-1);
    }