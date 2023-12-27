#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

const int N = 1e5 + 7;
vector<int> adj[N];
int Par[N];
int g[N];
int dp[N] ;

void dfs(int curr, int par)
{
    int maxi1 = 0, maxi2 = 0;
    for (auto it : adj[curr])
    {
        if (it != par)
        {
            dfs(it, curr);
            g[curr] = max(g[curr], g[it] + 1);
            dp[curr] = max(dp[curr], dp[it]);

            if (g[it] + 1 > maxi1)
            {
                maxi2 = maxi1;
                maxi1 = g[it] + 1;
            }

            else if (g[it] + 1 > maxi2)
            {
                maxi2 = g[it] + 1;
            }
        }
    }

    dp[curr] = max(dp[curr], (maxi1 + maxi2));
    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1 ,0);

   for(int i = 1 ; i <= n ; i++)
    cout<<i<<" "<<dp[i]<<endl;

}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}
