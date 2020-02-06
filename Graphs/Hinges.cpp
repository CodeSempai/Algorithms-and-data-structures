#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int n, m;
int T = 0;
int hinge_cnt = 0;
int tin[100000];
int d[100000];
bool used[100000];
vector<int> g[100000];
vector<int> ans;
map<int, int> check;


void find_hinges(int v, int e_in = -1){
    used[v] = true;
    T += 1;
    tin[v] = T;
    d[v] = tin[v];
    int childs = 0;
    for(int i = 0; i < g[v].size(); i++){
        if(g[v][i] == e_in)
            continue;
        if(used[g[v][i]])
            d[v] = min(d[v], tin[g[v][i]]);
        else{
            find_hinges(g[v][i], v);
            d[v] = min(d[v], d[g[v][i]]);
            if (d[g[v][i]] >= tin[v] && e_in != -1 && check[v] == 0) {
                check[v] = 1;
                hinge_cnt += 1;
                ans.push_back(v);
            }
            childs += 1;
        }


    }
    if(e_in == -1 && childs > 1 && check[v] == 0){
        check[v] = 1;
        hinge_cnt += 1;
        ans.push_back(v);
    }
}


int main()
{
    int x, y;

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    for(int i = 0;i < n; i++){
        used[i] = false;
    }

    for(int i = 0;i < n; i++)
        if(!used[i]) {
            find_hinges(i);
        }

    cout << hinge_cnt << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size();i++)
        cout << ans[i] + 1 << " ";

    return 0;
}
