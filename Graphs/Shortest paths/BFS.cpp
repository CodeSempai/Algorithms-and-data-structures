#include <bits/stdc++.h>
using namespace std;
vector <int> g[30000];
int n, m;
int x, y;
int start = 0;
queue<int> q;
int d[100000];
int used[100000];

void BFS(){
    q.push(start);
    d[start] = 0;
    used[start] = 1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++){
            if (used[g[v][i]] == 0){
                d[g[v][i]] = d[v] + 1;
                used[g[v][i]] = 1;
                q.push(g[v][i]);
            }
        }
    }
}

int main()
{
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);

    std::ios_base::sync_with_stdio (false);

    cin >> n >> m;

    for(int i = 0;i < n;i++){
        used[i] = 0;
        d[i] = 0;
    }
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);

    }
    BFS();
    for(int i = 0; i < n;i++)
        cout << d[i] << " ";


    return 0;
}
