#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int n, m;
int T = 0;
int cnt = 0;
int tin[100000];
int d[100000];
int colors[100000];
int p[1000000];
int max_color = 0;
int last;
bool used[100000];
vector<int> g[100000];
vector<int> ans;
stack<int> st;
map<pair<int, int>, int> mult_edges;




void paint(int v){

    max_color += 1;
    last = -1;

    while(last != v && !st.empty()) {
        colors[st.top()] = max_color;
        last = st.top();
        st.pop();
    }

}


void find_bridges(int v, int e_in = -1){
    used[v] = true;
    T += 1;
    st.push(v);
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
            if (d[g[v][i]] > tin[v] && mult_edges[make_pair(v, g[v][i])] == 1)
                paint(g[v][i]);
        }
    }

}



int main()
{
    int x, y;

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        cin >> x >> y;
        mult_edges[make_pair(x - 1, y - 1)] += 1;
        mult_edges[make_pair(y - 1, x - 1)] += 1;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }



    for(int i = 0;i < n; i++){
        used[i] = false;
    }


    for(int i = 0;i < n; i++) {
        if (!used[i]) {
            find_bridges(i);
            paint(i);
        }
    }

    for(int i = 0;i < n; i++){
        used[i] = false;
        d[i] = 0;
        tin[i] = 0;
    }



    cout <<  max_color  << endl;


       for (int i = 0; i < n; i++) {
           cout << colors[i]  << " ";
       }


    return 0;
}
