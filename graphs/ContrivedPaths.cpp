#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

vector<vector<pair<int, ll>>> adjL(100005);

ll dist[100005];

void dijskra(ll n, ll b[], ll k){


    for(ll i = 0; i<k; i++){
        ll src = b[i];

        for(ll j =0; j<n+2; j++)
            dist[j] = 1e18;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        dist[src] = 0;
        pq.push({src, 0});
        
        while(!pq.empty()){
            ll node = pq.top().first;
            ll d = pq.top().second;
            pq.pop();
            
            for(auto &[v, w] : adjL[node]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({v, dist[v]});
                }
            }
        }

        for(int j = 0; j<n; j++)
            cout << dist[j] << " ";
        cout << '\n';
    }
    
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n]; 
    ll b[k];

    for(ll i =0; i<n; i++)
        cin >> a[i];

    for(ll i =0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        adjL[u].push_back({v, w});
        adjL[v].push_back({u, w});

    }

    for(ll i =0; i<n; i++){
        adjL[i].push_back({n, a[i]});
        adjL[n].push_back({i, a[i]});
    }

    for(ll i =0; i<k; ++i){
        cin >> b[i];
        b[i]--;
    }
    
    dijskra(n, b, k);

}

int main() {
    solve();

    return 0;
}
