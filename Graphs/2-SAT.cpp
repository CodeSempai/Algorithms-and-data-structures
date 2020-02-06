#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>


using namespace std;
vector<int> g[100000];
vector<int> gt[100000];
int used[100000];
vector<int> ord , cmp;
int n, m;
map<string, int> names;
map<int, string> numbers;
vector<int> answer;
vector<string> bad;



int get_name(string s){
    if (s[0] == '+') {
        return 2 * names[s.substr(1 )] - 2;
    } else {
        return 2 * names[s.substr(1)] - 1;
    }
}





void dfs1(int v){
    used[v] = 1;
    for(int i = 0;i < g[v].size();i++){
        if(!used[g[v][i]])
            dfs1(g[v][i]);
    }
    ord.push_back(v);
}

void dfs2(int v, int cnt){
    cmp[v] = cnt;
    for(int i = 0; i < gt[v].size();i++){
        if(cmp[gt[v][i]] == -1)
            dfs2(gt[v][i], cnt);
    }
}


int main() {

    string check;
    string name;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name;
        names[name] = i + 1;
        numbers[i] = name;
    }

    string c, first, second;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0)
                cin >> first;
            else if (j == 2)
                cin >> second;
            else
                cin >> c;
        }


        if(first[0] == '+')
            first[0] = '-';
        else
            first[0] = '+';

        g[get_name(first) ^ 1].push_back(get_name(second));
        g[get_name(second) ^ 1].push_back(get_name(first));
        gt[get_name(second)].push_back(get_name(first) ^ 1);
        gt[get_name(first)].push_back(get_name(second) ^ 1);
    }


    for (int i = 0; i < 2 * n; i++)
        if (!used[i])
            dfs1(i);

    cmp.assign(2 * n, -1);

    for (int i = 0, cnt = 0; i < 2 * n; i++) {
        int v = ord[2 * n - 1 - i];
        if (cmp[v] == -1) {
            dfs2(v, cnt++);
        }
    }

    for (int i = 0; i < 2 * n; i += 2) {
        if (cmp[i] == cmp[i ^ 1]) {
            bad.push_back(numbers[i / 2]);
        }
    }

    for (int i = 0; i < 2 * n; i += 2) {
        int ans = cmp[i] > cmp[i ^ 1] ? i : i ^ 1;
        if(ans != i ^ 1)
        answer.push_back(ans);
    }



    if(answer.size() == 0 || bad.size() == n){
        cout << -1;
        return 0;
    }

    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << numbers[answer[i] / 2] << endl;

    return 0;
}
