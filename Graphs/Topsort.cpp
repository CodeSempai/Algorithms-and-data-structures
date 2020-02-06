#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector <int> g[300000];
vector <int> topsorted;
int used[100000];
bool cycle = false;
int n, m;
int x, y;



void dfs(int v){
    used[v] = 1;
    for(int i = 0;i < g[v].size();i++){
        int next = g[v][i];
        if(used[next] == 0)
            dfs(next);
        if(used[next] == 1)
            cycle = true;
    }
    used[v] = 2;
    topsorted.push_back(v);
}

void topsort(){
    for(int i = 0;i < n;i++)
        used[i] = false;
    topsorted.clear();
    for(int i = 0;i < n;i++)
        if(!used[i])
            dfs(i);
    reverse(topsorted.begin(), topsorted.end());

}


int main()
{
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    topsort();

    if(cycle)
        cout << -1;
    else{
        for(int i = 0;i < n;i++)
            cout << topsorted[i] + 1 << " ";
    }

    return 0;
}
