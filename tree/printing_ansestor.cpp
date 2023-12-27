#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
#define f first 
#define s second
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>


const int N = 1e5 + 7; 
vector<int> adj[N] ;
int Par[N] ;

void dfs(int curr , int par)
       {
          cout<<curr<<" ";
          Par[curr] = par ;

          for(auto it : adj[curr])
            {
                if(it != par)
                  {
                    dfs(it , curr);
                  }
            }
       }

void solve()
     {
         int n ;
         cin>>n;

         for(int i = 0 ; i < n-1 ; i++)
           {
             int u , v ;
             cin>>u>>v;

             adj[u].push_back(v);
             adj[v].push_back(u);

           }

        dfs(1 ,0);

        for(int i  = 1 ; i <= n ; i++)
          {
            int node = Par[i] ;

           cout<<"ansector of"<<i<<" : ";
            while (node != 0)
            {
              cout<<node<<" ";
               node = Par[node];         
            }
            
            cout<<endl;
          }

        
        return ;
     }

int main()
  {
    
    #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r", stdin) ;
      freopen("output.txt" , "w" ,stdout);
    #endif

    int t = 1 ;
    // cin>>t;

    while (t--)
    {
      solve() ;
    }

  }
