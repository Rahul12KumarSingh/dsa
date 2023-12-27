/*
Subtree Problem
You are given a tree with n nodes rooted at 1  where each node is numbered 1 to n.

The tree is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi , and also you are given an array of queries where query[i] = ui , you have to count the number of nodes present in the subtree of  node ui for each query.

Return an array containing the answer of each query respectively.

Example:

Input
n = 5
edges = [
    [1, 2],
    [1, 3],
    [3, 4],
    [3, 5]
]
queries = [ 1, 2, 3, 4, 5]
Output

[5, 1, 3, 1, 1]
*/
#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 7 ;
int dp[N] ;

void dfs(vector<int> adj[] , int  node  , int parent )
       {
          dp[node] = 1 ;
          for(auto it : adj[node])
              {
                  if(it != parent)
                     {
                        dfs( adj , it , node); 
                        dp[node] = dp[node] + dp[it] ;
                     }
              }
              
            return ; 
       }





