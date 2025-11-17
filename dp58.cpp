// 139. Word Break
// TC = O(n³) 
// isliye hai kyunki har index par O(n) loop chal raha hai aur har loop me substr O(n) time leta hai → n * n * n = O(n³).

class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string> &st, vector<int> &dp) {
        if (idx == s.size()) return true;   // poora string break ho gaya

        if (dp[idx] != -1) return dp[idx];  // memo check

        for (int end = idx; end < s.size(); end++) {
            string sub = s.substr(idx, end - idx + 1);

            if (st.count(sub)) {
                if (solve(end + 1, s, st, dp)) 
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;   // koi partition nahi mila
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);  // -1 = unvisited, 0 = false, 1 = true

        return solve(0, s, st, dp);    // recursion start from index 0
    }
};
