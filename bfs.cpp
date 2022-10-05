/**
 * Code Written by hritikhrk (Hritik Kumar)
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
vector<vector<int>> adj; //adjacency list representation
int n;                   //number of nodes
int s;                   //source vertex

queue<int> q;
vector<bool> used;
vector<int> d, p;

inline ll mod(ll x, ll m)
{
    return (x % m + m) % m;
}

vector<int> bfs()
{
    vector<int> res;
    q.push(s);
    res.push_back(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if (!used[u])
            {
                res.push_back(u);
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    return res;
}

void shortestPath(int u)
{
    if (!used[u])
        cout << "NO Path!\n";
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path of " << u << ": ";
        for (int v : path)
            cout << v << " ";
    }
    return;
}

void solve()
{
    cin >> n >> s;
    adj.clear();
    adj.resize(n + 1);
    used.resize(n + 1);
    p.resize(n + 1);
    d.resize(n + 1);
    cout << adj.size() << endl;
    int numberOfEdges;
    cin >> numberOfEdges;
    int u, v;
    for (int i = 0; i < numberOfEdges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Adj list:" << endl;
    for (int i = 1; i < adj.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> bfs_path = bfs();
    cout << "BFS route:" << endl;
    for (int i = 0; i < bfs_path.size(); i++)
    {
        cout << bfs_path[i] << " ";
    }

    cout << "\nd[] = ";
    for (int i = 1; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl
         << "p[] = ";
    for (int i = 1; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        shortestPath(i);
        cout << endl;
    }
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
    // int testCases;
    // cin >> testCases;
    // while (testCases--)
    solve();
    // Code end here //
    return 0;
}

/**
 * Sample test case 1:
6 1
8
1 2
1 3
2 4
2 5
3 5
4 5
4 6
5 6

 * Output:
7
Adj list:
1 => 2 3 
2 => 1 4 5 
3 => 1 5 
4 => 2 5 6 
5 => 2 3 4 6 
6 => 4 5 
BFS route:
1 2 3 4 5 6 
d[] = 0 1 1 2 2 3 
p[] = -1 1 1 2 2 4 
Path of 1: 1 
Path of 2: 1 2 
Path of 3: 1 3 
Path of 4: 1 2 4 
Path of 5: 1 2 5 
Path of 6: 1 2 4 6 

 */