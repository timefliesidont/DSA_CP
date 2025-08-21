#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[150005];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjL(n);

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    for(int i = 0; i<n; i++){
        if(visited[i])
            continue;
        vector<int> components;

        queue<int> Q;
        Q.push(i);
        visited[i] = true;
        
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            components.push_back(node);

            for(auto neighbour : adjL[node]){
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    Q.push(neighbour);
                }
            }
        }

        for(auto node : components){
            if(adjL[node].size() != (components.size()-1)){
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
}

int main(){

    solve();

    return 0;
}
