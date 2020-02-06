#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
vector<pair<int, int> > cord;
//vector <vector<float> > g;
vector<bool> used;
vector<float> min_edge;
float x, y, w;
float cost = 0;

double get_w(int i, int j){
    return sqrt(((cord[j].first - cord[i].first) * (cord[j].first - cord[i].first)) + ((cord[j].second - cord[i].second) * (cord[j].second - cord[i].second)));
}


int main()
{



    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> x >> y;
        cord.push_back(make_pair(x, y));
    }


    min_edge.resize(n);
    for(int i = 0;i < n;i++)
        min_edge[i] = 100000000000;
    used.resize(n);
    for(int i = 0; i < n;i++)
        used[i] = false;

    min_edge[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || min_edge[j] < min_edge[v]))
                v = j;
        used[v] = true;

        for (int next = 0; next < n; next++) {
            if (!used[next] && get_w(v, next) < min_edge[next]) {
                min_edge[next] = get_w(v, next);;
            }
        }
    }

    for(int i = 0;i < min_edge.size();i++)
        cost += min_edge[i];

    cout.precision(20);
    cout << cost;

    return 0;
}
