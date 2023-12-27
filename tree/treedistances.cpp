/*
  Tree Distances
You are given a tree with n nodes where each node has labels in the set {1,2,.......,n} .

The tree is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi , you have to return for each node the maximum distance to any another node.

Return an array containing the answer of each node from  1 to n  respectively.

Constraints:

1≤ n ≤10^5

0<= edges.length <= n-1

Example:

Input
n = 5
edges = [
    [1, 2],
    [1, 3],
    [3, 4],
    [3, 5]
]

Output
[2, 3, 2, 3, 3]


Approach just use the tree daimeter concept to finding the diameter end point nodes node1 and node2 find the distance of all the node from node1 and node2 take it makimum that will be the final answer...

*/


#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int> adj[] , int node , int parent , int cost , vector<int> &dis)
        {
            
            dis[node] = cost ;
            
            for(auto it : adj[node])
              {
                  if(it != parent)
                      {
                          dfs(adj , it , node , cost + 1 , dis);
                      }
              }
               
              return; 
        }
          

vector<int> treeDistances(int n, vector<vector<int>>edges)
  {
    vector<int> adj[n+1] ;

    for(auto it : edges)
      {
          adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]) ;
      }
       
   vector<int> dis(n+1) , dis1(n+1) , dis2(n+1)  ;
   
   
   //it give the distance of the all nodes from the source nodes...
   dfs(adj , 1 , 0 ,0 ,  dis);
   
   
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
     
   cout<<node1<<" "<<endl;
  
  
   dfs(adj , node1 , 0 , 0 , dis1);
   
   //now find the node2..
   int node2 = -1 ;
   maxi = INT_MIN ;
   
   for(int i = 1 ; i <= n; i++ )
     {
         if(maxi < dis1[i])
            {
                node2 = i ;
                maxi = dis1[i] ;
            }
     }
     
    cout<<node2<<" ";
    
   dfs(adj , node2 , 0 , 0 , dis2);
   
   vector<int> res ;
   
   for(int i = 1 ; i <= n ; i++)
      {
          res.push_back(max(dis1[i] , dis2[i])) ;
      }
   
    return res ;
    
  }