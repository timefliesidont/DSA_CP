#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long

using namespace std;

int a[100005] = {0};
int b[10] = {0};
int dist[100005];
int visited[100005];

void solve() {
    int n, m, k;

    cin >> n >> m >> k;
    vector<pair<int, int>> adjL[n];

    for(ll i =0; i<n; ++i)
        cin >> a[i];

    for(ll i =0 ; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;

        adjL[u].push_back({v, w});
        adjL[v].push_back({u, w});
    }

    for(ll i =0; i<k; ++i){
        cin >> b[i];
        --b[i];
    }

    for(ll i =0; i<k; ++i){
        for(ll i = 0; i<n; ++i)
            dist[i] = 1e9;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[b[i]] = 0;
        pq.push({0, b[i]});

        while(!pq.empty()){
            auto &[d, node] = pq.top();
            pq.pop();

            if(visited[node])   continue;
            visited[node] = 1;
            
            for(auto &[v, w] : adjL[node]){
                if(w + d < dist[v]){
                    dist[v] = w + d;
                    pq.push({dist[v], v});
                }
            }
        }
        
        cout << '\n';
    }

}

int main () {
    solve();

    return 0;
}

