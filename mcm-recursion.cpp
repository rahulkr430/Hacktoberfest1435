/**
 * Code Written by hritikhrk (Hritik Kumar)
 */

/**
 * Problem Link: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
 * Given a sequence of matrices,
 * find the most efficient way to multiply these matrices together.
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

int dp[1001][1001];
int mcmRec(vector<int> &v, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    // for (int k = i+1; k <= j; k++)
    // {
    //     int temp = mcm(v,i,k-1) + mcm(v,k,j) + (v[i-1]*v[k-1]*v[j]);
    //     mn = min(temp, mn);
    // }
    for (int k = i; k < j; k++)
    {
        int left = 0, right = 0;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = mcmRec(v, i, k);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = mcmRec(v, k + 1, j);
            dp[k + 1][j] = right;
        }
        int temp = left + right + (v[i - 1] * v[k] * v[j]);
        mn = min(temp, mn);
    }
    return dp[i][j] = mn;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << mcmRec(v, 1, n - 1) << endl;
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

// #TESTCASES:-
// #INPUT:
// 3
// 5
// 40 20 30 10 30
// 5
// 10 20 30 40 30
// 3
// 10 20 30

// #OUTPUT:
// 26000
// 3000
// 6000