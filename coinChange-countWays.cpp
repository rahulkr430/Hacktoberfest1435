/**
 * Code Written by hritikhrk (Hritik Kumar)
 */

/**
 * Problem Link: https://leetcode.com/problems/coin-change-2/
 * given an integer array coins representing coins of different denominations
 * and an integer amount representing a total amount of money.
 * Return the number of combinations that make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return 0.
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

// Recursive solution
int dp[305][5005];
int countWaysCoinChange(vector<int> &coins, int amount, int n)
{
    if (n == 0 || amount < 0)
        return 0;
    if (amount == 0)
        return 1;
    if (dp[n][amount] != -1)
        return dp[n][amount];
    if (coins[n - 1] <= amount)
        return dp[n][amount] = countWaysCoinChange(coins, amount - coins[n - 1], n) + countWaysCoinChange(coins, amount, n - 1);
    else
        return dp[n][amount] = countWaysCoinChange(coins, amount, n - 1);
    return 0;
}

// 1-d dp solution
int coinChange1DP(vector<int> &coins, int amount, int n)
{
    int t[amount + 1];
    memset(t,0,sizeof(t));
    t[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if(j >= coins[i])
            {
                t[j] += t[j-coins[i]];
            }
        }
    }
    return t[amount];
}

void solve()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    memset(dp, -1, sizeof(dp));
    // cout << countWaysCoinChange(coins, amount, n) << endl;   //recursion memoized
    cout << coinChange1DP(coins, amount, n) << endl;
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
// 1
// 7 500
// 3 5 7 8 9 10 11

// OUTPUT:
// 35502874