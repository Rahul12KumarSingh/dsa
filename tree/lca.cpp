#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

const int N = 1e5 + 7;
const int M = 20 ;

vector<int> adj[N];
int Par[N][M] ;
int Dep[N] ;

//finding the lowest common ansestor by using the binary lifting concept...

 void dfs(int curr , int par)
     {
        Dep[curr] = Dep[par] + 1 ;
        Par[curr][0] = par ;

        for(int j = 1 ; j < M ; j++)
          {
             Par[curr][j] = Par[Par[curr][j-1]][j-1] ;
          }

        for(auto it : adj[curr])
          {
             if(it != par)
               {
                  dfs(it , curr);
               }
          }

         return ;
     }

int lca(int u , int v)
       {
         if(u == v)
           return u ;

         dfs(1 , 0);

         if(Dep[u] < Dep[v]) swap(u , v);

         int diff = Dep[u] - Dep[v] ;

        for(int j = M-1 ; j >= 0 ; j--)
           {
              if((diff>>j) & 1)
                {
                  u = Par[u][j] ;
                }
           }

          if(u == v)
             return u ;

          for(int j = M-1 ; j >= 0 ; j--)
             {
                if(Par[u][j] != Par[v][j])
                   {
                      u = Par[u][j] ;
                      v = Par[v][j] ;
                   }
             }

            return Par[u][0] ;
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

    cout<<lca(u , v)<<endl;
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
