#include <iostream>
#include <vector>

using namespace std;

struct edge{

    int to;

    int w;

};

bool used[1000];

void dfs(vector< vector<edge> > &g, int v){

    used[v] = true;

    for (edge e: g[v]){

        if (!used[e.to]){

            dfs(g, e.to);

        }

    }

}

vector<int> ord, component;

void dfs1(vector< vector<edge> > &g, int v){

    used[v] = true;

    for (edge e: g[v]){

        if (!used[e.to]){

            dfs1(g, e.to);

        }

    }

    ord.push_back(v);

}

void dfs2(vector< vector<edge> > &gr, int v){

    used[v] = true;

    component.push_back(v);

    for (edge e: gr[v]){

        if (!used[e.to]){

            dfs2(gr, e.to);

        }

    }

}

void Condensation(vector< vector<edge> > &g, vector<int> &comps, int &cnt){

    vector< vector<edge> > gr(g.size());

    edge new_e;

    for (int i = 0; i < g.size(); i++){

        for (edge e: g[i]){

            new_e.to = i;

            gr[e.to].push_back(new_e);

        }

    }

    for(int i = 0; i < g.size(); i++)

        used[i] = false;

    ord.clear();

    for (int i = 0; i < g.size(); i++){

        if (!used[i]){

            dfs1(g, i);

        }

    }

    for(int i = 0; i < g.size(); i++)

        used[i] = false;

    for (int i = gr.size() - 1; i >= 0; --i){

        int v = ord[i];

        if (!used[v]){

            dfs2(gr, v);

            for(int i: component){

                comps[i] = cnt;

            }

            cnt++;

            component.clear();

        }

    }

}

long long findMST(vector< vector<edge> > &g, int n, int root)

{

    long long res = 0;

    int *minEdge = new int[n];

    for(int i = 0; i < n; ++i)

        minEdge[i] = 1000000000;

    for (vector<edge> i: g){

        for (edge e: i){

            minEdge[e.to] = min(e.w, minEdge[e.to]);

        }

    }

    for (int i = 0; i < n; ++i){

        if (i != root){

            res += minEdge[i];

        }

    }

    vector< vector<edge> > zeroEdges(n);

    for (int i = 0; i < g.size(); ++i){

        for (edge e: g[i]){

            if (e.w == minEdge[e.to]){

                zeroEdges[i].push_back(e);

            }

        }

    }

    for (int i = 0; i < n; ++i){

        used[i] = false;

    }

    dfs(zeroEdges, root);

    bool flag = false;

    for (int i = 0; (i < n) && (!flag); ++i){

        if (!used[i]){

            flag = true;

        }

    }

    if (!flag){

        return res;

    }

    int cnt = 0;

    vector<int> comps(n);

    Condensation(zeroEdges, comps, cnt);

    vector< vector<edge> > new_edges(cnt);

    edge new_edge;

    for (int i = 0; i < g.size(); ++i){

        for (edge e: g[i]){

            if (comps[i] != comps[e.to]){

                new_edge.to = comps[e.to];

                new_edge.w = e.w - minEdge[e.to];

                new_edges[comps[i]].push_back(new_edge);

            }

        }

    }

    res += findMST(new_edges, cnt, comps[root]);

    return res;

}

int main()

{

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; ++i){

        used[i] = false;

    }

    int from;

    edge e_input;

    vector< vector<edge> > g(n);

    for (int i = 0; i < m; ++i){

        cin >> from >> e_input.to >> e_input.w;

        e_input.to -= 1;

        g[from - 1].push_back(e_input);

    }

    dfs(g, 0);

    for (int i = 0; i < n; ++i){

        if (!used[i]){

            cout <<"NO";

            return 0;

        }

    }

    cout << "YES" << endl;

    cout << findMST(g, n, 0);

    return 0;

}
