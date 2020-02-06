#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int n, m;
int T = 0;
int bridge_cnt = 0;
int tin[100000];
int d[100000];
bool used[100000];
vector<int> g[100000];
vector<int> ans;
map<pair<int, int>, int > mp;


void find_bridges(int v, int e_in = -1){
    used[v] = true;
    T += 1;
    tin[v] = T;
    d[v] = tin[v];
    for(int i = 0; i < g[v].size(); i++){
        if(g[v][i] == e_in)
            continue;
        if(used[g[v][i]])
            d[v] = min(d[v], tin[g[v][i]]);
        else {
            find_bridges(g[v][i], v);
            d[v] = min(d[v], d[g[v][i]]);
            if (d[g[v][i]] > tin[v]) {
                bridge_cnt += 1;
                ans.push_back(mp[make_pair(v, g[v][i])]);
            }
        }

    }
}


int main()
{
    int x, y;

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        cin >> x >> y;
        mp[make_pair(x - 1, y - 1)] = i + 1;
        mp[make_pair(y - 1, x - 1)] = i + 1;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    for(int i = 0;i < n; i++){
        used[i] = false;
    }

    for(int i = 0;i < n; i++)
        if(!used[i]) {
            find_bridges(i);
        }

    cout << bridge_cnt << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size();i++)
        cout << ans[i] << " ";

    return 0;
}
