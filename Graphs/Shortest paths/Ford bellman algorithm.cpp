#include <bits/stdc++.h>
using namespace std;
int n, s , m;
long long cost;
int x, y ;
struct edge{
    int from, to;
    long long w;
};
vector<long long> d;
vector<long long> p;
int q[100000];
const long long INF = 2e18;
int used[2000];
vector<edge> e;
vector<pair<int, long long> > g[1000000];
 
void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size();i++){
        if(q[v])
            q[g[v][i].first] = 1;
        if(!used[g[v][i].first])
            dfs(g[v][i].first);
    }
 
}
 
 
int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
 
 
 
    cin >> n >> m >> s;
    d.resize(n);
    p.resize(n);
 
    for(int i = 0; i < n;i++){
        d[i] = INF;
    }
 
    for(int i = 0;i < m;i++){
        cin >> x >> y >> cost;
            edge new_e;
            new_e.from = x - 1;
            new_e.to = y - 1;
            new_e.w = cost;
            e.push_back(new_e);
            g[new_e.from].push_back(make_pair(new_e.to, new_e.w));
    }
 
   d[s - 1] = 0;
   for(int i = 0; i < n - 1;i++){
        for(int j = 0;j < m;j++){
            if (d[e[j].from]< INF){
               if(d[e[j].to] > d[e[j].from] + e[j].w){
                d[e[j].to] = max(-INF, d[e[j].from] + e[j].w);
               }
            }
        }
    }
 
    for(int i = 0; i < n;i++)
        for(int j = 0; j < g[i].size();j++)
            if((d[i] < INF) && (d[g[i][j].first] > d[i] + g[i][j].second) && !used[g[i][j].first])
                dfs(g[i][j].first);	//dfs нужен для задачи
 
    for(int i = 0; i < d.size();i++){
        if(used[i] || d[i] < -2e18)
            cout << "-" << endl;
        else if(d[i] == INF)
            cout << "*" << endl;
        else
            cout << d[i] << endl;
    }
 
    return 0;
}