/**
 * Code Written by hritikhrk (Hritik Kumar)
 */

/**
 * Problem link: https://leetcode.com/problems/target-sum/
 * given an integer array nums and an integer target.
 * build an expression out of nums by adding one of the symbols '+' and '-'
 * before each integer in nums and then concatenate all the integers.
 * Return the number of different expressions which evaluates to target.
 */

/**
 * Hint: This problem can be deduced to count subset with given diff.
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define F first
#define S Second
#define VI vector<int>
#define VLL vector<long long>
#define PII pair<int, int>
#define MII map<int, int>
#define pb push_back()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const int MOD = 1e9 + 7;

inline ll mod(ll x, ll m)
{
    return (x % m + m) % m;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (x > totalSum || (x + totalSum) % 2 != 0)
    {
        cout<<"0\n";
        return;
    }
    int sum = (x + totalSum) / 2;
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
    }
    cout << dp[n][sum] << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    IOS;

    //Code starts from here //
    int testCases;
    cin >> testCases;
    while (testCases--)
        solve();
    // Code end here //
    return 0;
}

// INPUT:
// 3
// 5 3
// 1 1 1 1 1
// 1 2
// 1
// 9 1
// 0 0 0 0 0 0 0 0 1

// OUTPUT:
// 5
// 0
// 256