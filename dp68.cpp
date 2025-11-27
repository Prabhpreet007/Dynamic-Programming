// 894. All Possible Full Binary Trees


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<TreeNode*>> dp;

    vector<TreeNode*> findAns(int n) {
        if (n % 2 == 0) {
            return {};
        }

        if (dp[n].size() != 0) {
            return dp[n];
        }

        if (n == 1) {
            TreeNode* temp = new TreeNode(0);
            return {temp};
        }

        vector<TreeNode*> ans;
        for (int i = 1; i < n; i += 2) {

            vector<TreeNode*> left = findAns(i);
            //i btayega ki left me currently kitni nodes hai 
            vector<TreeNode*> right = findAns(n - i - 1);
            // n-i-1 btayega ki right me currently kitni nodes consider hogi

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(0);
                    //root yhi bnana hai coz agr bhar bna dia isko toh fir same root bar bar use hoga
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n + 1);
        return findAns(n);
    }
};