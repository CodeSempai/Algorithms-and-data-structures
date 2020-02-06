#include <bits/stdc++.h>
using namespace std;
int n, cost;
int x;
struct edge{
    int from, to , w;
};
vector<int> d;
vector<int> path;
vector<int> p;
vector<edge> e;
 
 
int main()
{
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
 
 
 
    cin >> n;
    d.resize(n);
    d.assign(n, 1000000000);
    p.resize(n);
    p.assign(n, -1);
 
 
    for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> cost;
            if(cost != 1000000000){
                edge new_e;
                new_e.from = i;
                new_e.to = j;
                new_e.w = cost;
                e.push_back(new_e);
            }
        }
    }
 
   for(int i = 0; i < n;i++){
        x = -1;
        for(int j = 0;j < e.size();j++)
            if (d[e[j].to] > d[e[j].from] + e[j].w) {
                d[e[j].to] = max (-1000000000, d[e[j].from] + e[j].w);
                p[e[j].to] = e[j].from;
                x = e[j].to;
            }
   }
   if(x == -1){
        cout << "NO";
        return 0;
   }else{
        int y = x;
        for(int i = 0;i < n; i++)
            y = p[y];
 
        for(int i = y; ; i = p[i]){
            path.push_back(i);
            if(i == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.size() << endl;
        for(int i = 0; i < path.size();i++)
            cout << path[i] + 1 << " ";
 
   }
 
    return 0;
}