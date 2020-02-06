#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

int n, m;
int T = 0;
int max_clr = 0;
int tin[100000];
int d[100000];
bool used[100000];
vector<int> g[100000];
vector<pair<int, int>> edges;
map<pair<int, int>, int> colors;

void find_hinges(int v, int e_in = -1) {
    used[v] = true;
    T += 1;
    tin[v] = T;
    d[v] = tin[v];
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] == e_in)
            continue;
        if (used[g[v][i]])
            d[v] = min(d[v], tin[g[v][i]]);
        else {
            find_hinges(g[v][i], v);
            d[v] = min(d[v], d[g[v][i]]);
        }
    }

}


void colorize(int v, int clr, int parent = -1){
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        if(g[v][i] == parent)
            continue;
        if(!used[g[v][i]]){
            if(d[g[v][i]] >= tin[v]){
                int new_clr = ++max_clr;
                colors[make_pair(v, g[v][i])] = new_clr;
                colorize(g[v][i], new_clr, v);
            }else{
                colors[make_pair(v, g[v][i])] = clr;
                colorize(g[v][i], clr, v);
            }
        }else if(tin[g[v][i]] < tin[v]) {
             colors[make_pair(v, g[v][i])] = clr;
        }
    }

}




int main()
{
    int x, y;

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        cin >> x >> y;
        edges.push_back(make_pair(x - 1, y - 1));
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    for(int i = 0;i < n; i++){
        used[i] = false;
    }


    for(int i = 0; i < n;i++) {
        if(!used[i])
            find_hinges(i);
    }

    for(int i = 0;i < n; i++){
        used[i] = false;
    }

    for(int i = 0; i < n;i++) {
        if (!used[i]) {
            colorize(i, max_clr);
        }
    }


    cout << max_clr << endl;

   for(int i = 0; i < edges.size();i++){
       if(colors[edges[i]] != 0)
        cout << colors[edges[i]]  << " ";
       else
           cout << colors[make_pair(edges[i].second, edges[i].first)]  << " ";
    }

    return 0;
}
