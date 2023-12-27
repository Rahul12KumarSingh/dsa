/*
Cut'em All!
You are given a tree with n vertices numbered 1 to n.

The tree is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between vertex ui and vertex vi.

Your task is to determine the maximum possible number of edges that can be removed in such a way that all the remaining connected components will have even size.

Return the maximum number of edges that can be removed to leave all connected components with even size, or −1 if it is impossible to remove edges in order to satisfy this property.

Constraints:
1≤ n ≤10^5
1<= edges.length <= n-1
1<= ui, vi <=n

Example:
Input
n = 4
edges = [
    [2, 4],
    [4, 1],
    [3, 1]
]

Output
1
Explanation
In the example, you can remove the edge between vertices 1 and 4. The graph after that will have two connected components with two vertices in each.

Expected Time Complexity: O(n)

Approach: find the subtree size of all the nodes if subtree size is even then increase the count by one at if count value is one it means that there is only one even value we cannot divide the further even group at the end return cnt - 1 ;
*/

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
int dp[N];

void dfs(int node, int parent)
{
    dp[node] = 1;
    for (auto it : adj[node])
    {
        if (it != parent)
        {
            dfs(it, node);
            dp[node] = dp[node] + dp[it];
        }
    }
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

    dfs(1, 0);
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] % 2 == 0)
            cnt++;
    }

    if (cnt <= 1)
        cout << "-1" << endl;

    else
        cout << (cnt - 1);

    return;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin>>t;

    while (t--)
    {
        solve();
    }
}
