// 96. Unique Binary Search Trees
// T.C= Exponential


class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1){
            return 1;
        }
        int result=0;
        for(int i=0;i<n;i++){
            result=result+(numTrees(i)*numTrees(n-i-1));
        }
        return result;
    }
};