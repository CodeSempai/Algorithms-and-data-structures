#include <fstream>      //Print poped elemets
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);

    int n;
    string com, temp;
    cin >> n;
    vector<string> queue;

    for(int i = 0;i < n;i++){
        cin >> com;
        if(com == "+"){
            cin >> temp;
            queue.push_back(temp);
        }else{
            cout << queue[0] << endl;
            for(int j = 0;j < queue.size() - 1;j++)
                queue[j] = queue[j+1];
             queue.pop_back();

            }

    }

    return 0;
}

