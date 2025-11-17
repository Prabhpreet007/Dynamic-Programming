
// 85. Maximal Rectangle

int findAns(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && v[stk.top()] >= v[i])
        {
            stk.pop();
        }
        if (stk.empty())
            left[i] = 0;
        else
        {
            left[i] = stk.top() + 1;
        }
        stk.push(i);
    }

    while (!stk.empty())
        stk.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && v[stk.top()] >= v[i])
        {
            stk.pop();
        }
        if (stk.empty())
            right[i] = n - 1;
        else
        {
            right[i] = stk.top() - 1;
        }
        stk.push(i);
    }

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int ans = (right[i] - left[i] + 1) * v[i];
        maxi = max(maxi, ans);
    }
    return maxi;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> v(m, 0);

    int maxAns = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                v[j] = v[j] + 1;
            }
            else
            {
                v[j] = 0;
            }
        }
        int ans = findAns(v);
        maxAns = max(maxAns, ans);
    }
    return maxAns;
}