//  House Robber II (CODING NINJAS)

#include <iostream>
#include <vector>
using namespace std;

long long int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    long long int prev2 = nums[0];
    if (n == 0)
        return prev2;

    long long int prev = max(nums[0], nums[1]);
    if (n == 1)
        return prev;

    for (int i = 2; i < n; i++)
    {
        long long int left = nums[i] + prev2;
        long long int right = 0 + prev;

        long long int curr = max(left, right);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    long long int n = valueInHouse.size();
    // if(n==0)return 0;

    if (n == 1)
    {
        return valueInHouse[0];
    }
    vector<int> temp1(valueInHouse.begin() + 1, valueInHouse.end());
    vector<int> temp2(valueInHouse.begin(), valueInHouse.end() - 1);

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}

int main()
{
    int n;
    cin >> n;
    vector<int> valueInHouse(n);
    for (int i = 0; i < n; i++)
    {
        cin >> valueInHouse[i];
    }
    cout << houseRobber(valueInHouse);

    return 0;
}