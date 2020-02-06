#include <bits/stdc++.h>
using namespace std;
vector <int> g[300000];
int n, m;
int x, y;
int cnt = 1;
queue<int> q;
bool used[100000];
int numb[200000];
 
void dfs(int v){
    used[v] = true;
    numb[v] = cnt ;
    for(int i = 0;i < g[v].size();i++){
        int next = g[v][i];
        if(!used[next])
            dfs(next);
    }
}
 
void get_comps(){
    for(int i = 0;i < n;i++){
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    }
}
 
int main()
{
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
 
    std::ios_base::sync_with_stdio (false);
 
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        used[i] = false;
 
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
 
   get_comps();
   cout << cnt - 1 << endl;
   for(int i = 0;i < n;i++)
    cout << numb[i] << " ";
 
 
    return 0;
}