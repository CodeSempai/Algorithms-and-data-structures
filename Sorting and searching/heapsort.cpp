#include<stdlib.h>
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;




void Max_Heapify(int arr[], int i, int n){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l <= n && arr[l] > arr[i]){
        largest = l;
    }
    if(r <= n && arr[r] > arr[largest]){
        largest=r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);

        Max_Heapify(arr, largest, n);
    }


}


void Build_Max_Heap(int arr[], int n){

    for(int i = n / 2 - 1 ; i >= 0; i--){
        Max_Heapify(arr, i, n - 1);
    }
}


void HeapSort(int arr[], int  n){

    Build_Max_Heap(arr, n);

    for(int i = n - 1;i >= 1;i--){

        swap(arr[0], arr[i]);

        Max_Heapify(arr, 0, i - 1);
    }


}






int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int arr[100000];
    int n;

    cin >> n;

    for(int i = 0; i < n;i++)
        cin >> arr[i];

    HeapSort(arr, n);

    for(int i = 0; i < n;i++)
        cout << arr[i] << " ";


    return 0;
}
