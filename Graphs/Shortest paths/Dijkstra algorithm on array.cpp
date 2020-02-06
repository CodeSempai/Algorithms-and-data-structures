#include <bits/stdc++.h>
using namespace std;
int n, s, f;
long long g[2000][2000];
vector<long long> d;
vector<bool> used;
const long long INF = 2e18;
 
 
int main()
{
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> s >> f;
    used.resize(n);
    used.assign(n, 0);
    d.resize(n);
    d.assign(n, INF);
 
    for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> g[i][j];
            if(g[i][j] == -1)
                g[i][j] = INF;
        }
    }
 
    d[s - 1] = 0;
    int vert = s - 1;
 
    for(int i = 0;i < n - 1;i++){
        used[vert] = 1;
        for(int j = 0;j < n;j++){
            if(d[vert] + g[vert][j] < d[j])
                d[j] = d[vert] + g[vert][j];
        }
        long long minimum = INF;
        int temp;
        for(int j = 0; j < n;j++){
            if(!used[j] && d[j] < minimum){
                minimum = d[j];
                temp = j;
            }
        }
        if(minimum == INF)
            break;
        vert = temp;
 
    }
 
 
 
    if(d[f - 1] != INF)
        cout << d[f - 1];
    else
        cout << "-1";
 
 
 
    return 0;
}