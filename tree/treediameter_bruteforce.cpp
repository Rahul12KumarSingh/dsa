/*
Tree Diameter--->

Given an undirected tree, return its diameter: the number of edges in the longest path in that tree.

The tree is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi. Each node has labels in the set {1,2,.......,edges.length+1}.


Brute force approach

take the any node as the root node . using djkstra algorithms find the largest distance node from the root node . mark it as the node1 . taking node1 as the root node find the largest distance node from node2 . mark it node2 . the distance between node1 and node2 will be the diameter distance .

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
int Par[N];


void dfs(  int node , int parent , int cost , vector<int> &dis)
        {
            dis[node] = cost ;
            
            for(auto it : adj[node])
              {
                  if(it != parent)
                      {
                          dfs( it , node , cost + 1 , dis);
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

   vector<int> dis(n+1 , 0) , dis1(n+1 , 0) ;  
   dfs( 1 , 0 ,0 ,  dis);
   
   //find the largest distance node from the root node...
   int node1 = -1 , maxi = INT_MIN ;
   
   for(int i = 1 ; i <= n; i++ )
     {
         if(dis[i] > maxi)
           {
               maxi = dis[i] ;
               node1 = i ;
           }
     }
     
   dfs( node1 , 0 , 0 , dis1);
   int res = 0 ;
   
   for(int i = 1 ; i <= n; i++ )
     {
         res = max(res , dis1[i]) ;
     }
   
    cout<<res<<endl;
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
