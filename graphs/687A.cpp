#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> adjL[100005];
vector<int> visited(100005, -1);

void solve(int tc = 0){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    vector<int> set0;
    vector<int> set1;

    //components
    for(int i = 0; i<n; ++i){
        if(visited[i] != -1)  continue;

        queue<pair<int, int>> Q;
        Q.push({i, -1});
        visited[i] = 0;
        set0.push_back(i+1);

        while(!Q.empty()){
            int node = Q.front().first;
            int parent = Q.front().second;
            Q.pop();

            for(auto neighbour: adjL[node]){
                if(visited[neighbour] == -1){
                    if(visited[node] == 0){
                        visited[neighbour] = 1;
                        set1.push_back(neighbour+1);
                    }
                    else{
                        visited[neighbour] = 0;
                        set0.push_back(neighbour+1);
                    }
                    Q.push({neighbour, node});
                }
                else if(neighbour != parent){
                    if(visited[neighbour] == visited[node])
                    {
                        cout << -1;
                        return;
                    }
                }
            }
        }
    }

    cout << set0.size() << '\n';
    for(int i =0; i<set0.size(); ++i)
        cout << set0[i] << " ";
    cout << endl;

    cout << set1.size() << '\n';
    for(int i =0; i<set1.size(); ++i)
        cout << set1[i] << ((i != set1.size()) ? " " : "");


}


int main(){
    solve(1);
}
