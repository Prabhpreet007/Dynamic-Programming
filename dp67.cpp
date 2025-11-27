// 1553. Minimum Number of Days to Eat N Oranges
// t.c= log₂(n)  OR  log₃(n) or log(n)

// esme ham tb tk n ko -1 krenge jb tk wo %3 yn %2 ni ho jata toh usko directly hamne n%2 and n%3 krke add kr lia

class Solution {
public:
    int findAns(int n, unordered_map<long long, int>& dp) {
        if (n == 1 || n == 0)
            return n;

        if (dp[n]) {
            return dp[n];
        }

        int a = (n % 2) + 1 + findAns(n / 2,dp);
        int b = (n % 3) + 1 + findAns(n / 3,dp);

        return dp[n] =  min(a,b);
    }

    int minDays(int n) {
        unordered_map<long long, int> dp;
        return findAns(n, dp);
    }
};