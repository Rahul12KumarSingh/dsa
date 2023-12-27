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
int Dep[N] ;

void dfs(int curr , int par)
     {
        Par[curr] = par ;
        Dep[curr] = Dep[par] + 1 ;

       for(auto it : adj[curr])
         {
            if(it != par)
              {
                dfs(it , curr);
              }
         }
     }

int find_lcs(int u , int v)
         {
            if(u == v)
              return u ;

            dfs(1 , 0) ;

            if(Dep[u] < Dep[v]) swap(u , v) ;

            int diff = Dep[u] - Dep[v] ;

            while (diff--)
            {
                u = Par[u] ;
            }

            if(u == v)
              return u ;
            
            while (Par[u] != Par[v])
            {
                u = Par[u] ;
                v = Par[v] ;
            }
            
            return Par[u] ;
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

   int u , v ;
   cin>>u>>v;

   cout<<find_lcs(u , v)<<endl;
   
   return ;
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
