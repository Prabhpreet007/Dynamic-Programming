// 10. Regular Expression Matching

// At every "x*" case, tum do choices lete ho:
// Skip "x*" → move j + 2
// Use "x*" → consume one char → move i + 1
// aur worst case me har step pe ho sakta hai.
//T.C = O(2^(m + n))


class Solution {
public:
    bool findAns(string& s, string& p, int i, int j) {
        if (i == s.size() && j == p.size())
            return true;

        if (j == p.size())
            return false;

        bool currMatch = false;
        if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
            currMatch = true;

        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Two possibilities:
            // 1. Skip the "x*" part in pattern
            // 2. If current matches, use "*" to match more of same char
            return findAns(s, p, i, j + 2) ||
                   (currMatch && findAns(s, p, i + 1, j));
        }

        if (currMatch)
            return findAns(s, p, i + 1, j + 1);

        return false;
    }

    bool isMatch(string s, string p) { 
        
        return findAns(s, p, 0, 0); 
    
    }
};




// DP SOLUTION
// T.C = O(m × n)

class Solution {
public:
    bool findAns(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.size() && j == p.size())
            return true;

        if (j == p.size())
            return false;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }    

        bool currMatch = false;
        if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
            currMatch = true;

        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Two possibilities:
            // 1. Skip the "x*" part in pattern
            // 2. If current matches, use "*" to match more of same char
            return dp[i][j]= findAns(s, p, i, j + 2, dp) ||
                   (currMatch && findAns(s, p, i + 1, j, dp));
        }

        if (currMatch)
            return dp[i][j]= findAns(s, p, i + 1, j + 1, dp);

        return dp[i][j]= false;
    }

    bool isMatch(string s, string p) { 
        vector<vector<int>>dp(s.length()+1,vector<int>(p.size()+1,-1));    
        return findAns(s, p, 0, 0, dp); 
    
    }
};