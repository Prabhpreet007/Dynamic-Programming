// Same question previous one solved

// T.C=O(nlogn)
// lowerbound is using the approach of binary search

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[ind] = arr[i];
        }
    }
    return ans.size();
}