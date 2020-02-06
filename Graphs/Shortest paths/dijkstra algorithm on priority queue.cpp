#include <bits/stdc++.h>
using namespace std;
int n, s, f;
long long x, y, w;
vector< vector<pair<int, long long> > > g;
vector<long long> d;
priority_queue<pair<long long, long long> > q;
const long long INF = 2e18;
 
int main()
{
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> s >> f;
    g.resize(n);
    d.resize(n);
    d.assign(n, INF);
 
 
    for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> w;
            if(w != -1 && w != 0)
                g[i].push_back(make_pair(j, w));
        }
    }
    d[s - 1] = 0;
       q.push(make_pair(0 , s - 1));
       while(!q.empty()){
        long long v = q.top().second;
        int cur = -q.top().first;
        q.pop();
        if(cur > d[v])
            continue;
        for(int j = 0; j < g[v].size();j++){
            int next = g[v][j].first;
            long long l = g[v][j].second;
            if(d[v] + l < d[next]){
                d[next] = d[v] + l;
                q.push(make_pair(-d[next], next));
            }
 
        }
    }
 
   if(d[f - 1] != INF)
        cout << d[f - 1];
    else
        cout << "-1";
 
 
 
    return 0;
}