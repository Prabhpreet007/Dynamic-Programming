// 368. Largest Divisible Subset (L.C)
//  Divisible Set

//T.C=O(N^2)

vector<int> divisibleSet(vector<int> &nums)
{
        
        int n=nums.size();
        sort(nums.begin(),nums.end());//IMPORTANT
        vector<int>dp(n,1),hash(n);

        int maxi=1;
        int maxIndex=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])//IMPORTANT
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                maxIndex=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxIndex]);
        
        while(maxIndex!=hash[maxIndex]){
            maxIndex=hash[maxIndex];

            ans.push_back(nums[maxIndex]);
        }
        reverse(ans.begin(),ans.end());

        return ans;
        
        }