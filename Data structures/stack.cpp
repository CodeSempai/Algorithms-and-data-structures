//Stack that based on vector.'+' - push. '-' - pop. Printing extracting elements

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> stack;
    int n;
    string com, temp;
    cin >> n;

    for(int i = 0;i < n;i++){
         cin >> com;
        if(com == "+"){
            cin >> temp;
            stack.push_back(temp);
        }else{
            cout << stack.back() << "\n";

             stack.pop_back();
        }

    }


    return 0;
}
