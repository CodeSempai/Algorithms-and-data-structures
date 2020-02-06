#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);

    int n;
    char com;
    int temp;
    cin >> n;
    stack<pair<int, int> > s1, s2;
    std::ios::sync_with_stdio(false);
    for(int i = 0;i < n;i++){
        cin >> com;
     if(com == '+'){
        cin >> temp;
        int minima = s1.empty() ? temp : min(temp, s1.top().second);
        s1.push (make_pair (temp, minima));
    }else if(com == '-'){
        if (s2.empty())
            while (!s1.empty()) {
		int element = s1.top().first;
		s1.pop();
		int minima = s2.empty() ? element : min (element, s2.top().second);
		s2.push (make_pair (element, minima));
	}

    s2.pop();




    }else{
            if (s1.empty() || s2.empty()){
            int current_minimum = s1.empty() ? s2.top().second : s1.top().second;
            cout << current_minimum << endl;
            }
            else{
            int current_minimum = min (s1.top().second, s2.top().second);
            cout << current_minimum << endl;
            }
    }


    }

    return 0;
}

