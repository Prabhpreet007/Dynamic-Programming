// 95. Unique Binary Search Trees II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:

    vector<TreeNode*> findAns(int start,int end){
        if(start>end){
            return {nullptr};
        }
        if(start==end){
            TreeNode* root=new TreeNode(start);
        }        
        
        vector<TreeNode*>ans;

        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftBST=findAns(start,i-1);
            vector<TreeNode*>rightBST=findAns(i+1,end);
            
            for(auto left:leftBST){
                for(auto right:rightBST){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                }
            }
        }

        return ans;

    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans=findAns(1,n);
        return ans;
    }
};

