// 91. Decode Ways
// t.c = O(n)


class Solution {
public:

    int findAns(string& s, int i, vector<int>& dp) {

        // end reached → 1 valid decoding
        if (i == s.length()) 
            return 1;

        // number cannot start with 0
        if (s[i] == '0')
            return 0;

        if (dp[i] != -1) 
            return dp[i];

        int ways = 0;

        // TAKE single digit
        ways += findAns(s, i + 1, dp);

        // TAKE two digits (only if valid 10 to 26)
        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                ways += findAns(s, i + 2, dp);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return findAns(s, 0, dp);
    }
};
