#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define ll long long

using namespace std;

/*long long binMultiply(long long a, long long b, long long M){*/
/*  long long ans = 0;*/
/*  while (b>0){*/
/*    if(b&1){*/
/*      ans = (ans + a) % M;*/
/*    }*/
/*    a = (a + a) % M;*/
/*    b = b >> 1;*/
/*  }*/
/*  return ans;*/
/*}*/
/**/
/*int binaryExpo(int x, int n, int M){*/
/*  if(x == 0) return 0;*/
/*  if(n == 0) return 1;*/
/**/
/*  int ans = 1;*/
/*  while(n>0){*/
/*    if(n&1)*/
/*      ans = binMultiply(ans, x, M);*/
/**/
/*    x = binMultiply(x, x, M);*/
/*    n = n >> 1;*/
/*  }*/
/*  return ans;*/
/*}*/

ll dfs(vector<int> adj[], vector<bool>& visited, int node) {
    int total = 1;

    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            total += dfs(adj, visited, neighbour);
        }
    }
    return total;
}


void solve() {
    int n, m, k;
    cin >> n >> m;

    vector<int> adjL[n];
    vector<bool> visited(n, false);
    int result[n];
    
    for(int i = 0; i<m; i++){
        cin >> k;
        int v[k];
        for(int j = 0; j<k; j++){
            cin >> v[j];
            --v[j];
        }
        for(int j = 0; j+1<k; j++){
            adjL[v[j]].push_back(v[j+1]);
            adjL[v[j+1]].push_back(v[j]);
        }
    }
    for(int i = 0; i<n; i++){
        if(visited[i])
            continue;

        vector<int> component;
        queue<int> Q;
        Q.push(i);
        
        visited[i] = true;

        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            component.push_back(node);

            for(auto neighbour : adjL[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    Q.push(neighbour);
                }
                
            }
        }

        for(auto elm : component)
        {
            result[elm] = component.size();
        }
        
        
    }
    for(int i = 0; i<n; i++)
            cout << result[i] << ((i == n-1)? "" : " ");

} 

int main() {

  solve();

  return 0;
}
