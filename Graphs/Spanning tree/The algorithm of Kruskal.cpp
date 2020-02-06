#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > g;
int x, y, w;
long long cost = 0;
vector<int> p;

int dsu_get(int v){
    if(v == p[v])
        return v;
    else
        return p[v] = dsu_get(p[v]);
}

void dsu_unite(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand() & 1)
        swap (a, b);
    if(a != b)
        p[a] = b;
}



int main()
{
    cin >> n >> m;
    g.resize(m);
    for(int i = 0;i < m;i++){
        cin >> x >> y >> w;
        g[i].second.first = x;
        g[i].second.second = y;
        g[i].first = w;
    }


    sort(g.begin(), g.end());
    p.resize(n + 1);

    for(int i = 1;i <= n;i++)
        p[i] = i;

    for(int i = 0;i < m;i++){
        int a = g[i].second.first;
        int b = g[i].second.second;
        int l = g[i].first;
        if(dsu_get(a) != dsu_get(b)){
            cost += l;
            dsu_unite(a, b);
        }
    }

    cout << cost;

    return 0;
}
