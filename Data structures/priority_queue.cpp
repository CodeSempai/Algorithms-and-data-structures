#include <bits/stdc++.h>

using namespace std;

  pair<int, int> arr[1000000];
  int arr2[1000000];
  int l = 0;


void sift_up(int i){
    while(arr[i].first < arr[(i - 1) / 2].first){
        swap(arr2[arr[i].second], arr2[arr[(i - 1) / 2].second]);
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void sift_down(int i){
    int left;
    int right;
    int smallest;
    while(2 * i + 1 < l){
       left = 2 * i + 1;
       right = 2 * i + 2;
       smallest = left;
       if ((2 * i + 1 < l) && (arr[right].first < arr[left].first))
            smallest = right;
       if (arr[i].first <= arr[smallest].first)
            break;
       swap(arr2[arr[i].second], arr2[arr[smallest].second]);
       swap(arr[i], arr[smallest]);
       i = smallest;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    int x, y;
    int i = 0;
    int temp;
    string com;

    while(cin >> com) {

        if(com == "push"){
            cin >> temp;
            arr2[i] = l;
            arr[l] = make_pair(temp, i);
            l++;
            sift_up(l - 1);


        }else if(com == "extract-min"){
            if(l != 0){
                cout << arr[0].first << endl;
                swap(arr2[arr[l - 1].second], arr2[arr[0].second]);
                arr[0] = arr[l - 1];
                l--;
                sift_down(0);
            }else
                cout << "*" << endl;
            }else{
                cin >> x;
                cin >> y;
                arr[arr2[x - 1]].first = y;
                sift_up(arr2[x - 1]);

            }
        i++;
    }

   return 0;
}
