#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
struct reb
{
    int from;
    int to;
    int w;
};
 
int d[10001][10001];
int q[10001];
vector<reb> rebs;
const long long INF = 2e18;
 
 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n , m, s, k;
 
    cin >> n >> m >> k >> s;
 
    reb e;
    n++;
 
 
    for(int i = 0;i < m;i++){
        cin >> e.from >> e.to >> e.w;
        rebs.push_back(e);
    }
 
    for(int i = 1;i < n;i++)
        d[0][i] = INF;
 
    for(int i = 1;i < k + 1;i++)
        for(int j = 1;j < n;j++)
            d[i][j] = INF;
 
    d[0][s] = 0;
 
    for(int i = 0;i < k;i++)
        for(int j = 0; j < rebs.size();j++)
            if(d[i][rebs[j].from] != INF)
                d[i + 1][rebs[j].to] = min(d[i+1][rebs[j].to], d[i][rebs[j].from] + rebs[j].w);
 
    for(int i = 1;i < n;i++){
        if(d[k][i] != INF)
            cout << d[k][i] << endl;
        else
            cout << "-1" << endl;
    }
 
    return 0;
 
}