#include <bits/stdc++.h>
using namespace std;
int n, m;
char lab[102][103];
int used[102][103];
string way[102][103];
queue<pair<int,int> > q;
char c;
int Ti = -1;
int Tj = -1;
int Si = -1;
int Sj = -1;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    std::ios_base::sync_with_stdio (false);
 
    cin >> n >> m;
    if(m == 1 && n == 1){
        cout << -1;
        return 0;
    }
 
 
    for(int i = 0;i < 102;i++){
        for(int j = 0;j < 103;j++){
            lab[i][j] = '#';
        }
    }
 
    for(int i = 1; i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> c;
            lab[i][j] = c;
            if(c == 'T'){
                Ti = i;
                Tj = j;
                lab[i][j] = '.';
            }else if(c == 'S'){
                Si = i;
                Sj = j;
                lab[i][j] = '.';
            }
        }
    }
 
 
 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            used[i][j] = -1;
        }
    }
 
 
    used[Si][Sj] = 0;
    q.push(make_pair(Si, Sj));
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <= 1; dj++){
                if((di * di + dj * dj) == 1){
                    int x = cur.first + di;
                    int y = cur.second + dj;
                    if(used[x][y] == -1 && lab[x][y] == '.'){
                        used[x][y] = used[cur.first][cur.second] + 1;
                        q.push(make_pair(x, y));
                        string path = "";
                        if(di == 1 && dj == 0)
                            path = "D";
                        if(di == -1 && dj == 0)
                            path = "U";
                        if(di == 0 && dj == 1)
                            path = "R";
                        if(di == 0 && dj == -1)
                            path = "L";
                        way[x][y] = way[cur.first][cur.second] + path;
 
                    }
                }
            }
        }
    }
 
    cout << used[Ti][Tj] << endl;
    cout << way[Ti][Tj];
 
    return 0;
}