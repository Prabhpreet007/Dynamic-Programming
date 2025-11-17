// 84. Largest Rectangle in Histogram

// THIS QUESTION IS NOT OF DP BUT FOR NEXT QUESTION ITS REQUIRED 

int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>stk;

        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty())left[i]=0;
            else{
                left[i]=stk.top()+1;
            }
            stk.push(i);
        }

 while (!stk.empty()) {
        stk.pop();
    }
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty())right[i]=n-1;
            else{
                right[i]=stk.top()-1;
            }
            stk.push(i);

        }

        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(right[i]-left[i]+1)*heights[i]);
        } 
        return maxi;
    }