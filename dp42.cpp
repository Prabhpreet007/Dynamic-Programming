// Same prev question but also print in that

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,1),hash(n);

        int maxi=1;
        int maxIndex=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<=i-1;prev++){
                if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
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
        
        reverse(ans.begin(),ans.end()); //IMPORTANT
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }


        return maxi;

    }