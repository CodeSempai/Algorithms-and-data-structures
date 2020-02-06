#include<stdlib.h>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
 
int binSearchLeft(int arr[], int key,int left, int right){
 
        if(left <= right){
 
            int m = (left + right) / 2;
 
            if(arr[m] < key){
                return binSearchLeft(arr, key, m + 1,right);
                }
            else{
                if(arr[m] > key)
                    return binSearchLeft(arr, key, left, m - 1);
                else
                    if(arr[m - 1] != key || (m - 1) < 0 )
                        return m + 1;
                    else
                        return binSearchLeft(arr, key, left, m - 1);
 
                }
            }
         else
            return -1 ;
 
}
 
int binSearchRight(int arr[], int key,int left, int right, int n){
        if(left <= right){
 
            int m = (left + right) / 2;
 
            if(arr[m] < key){
                return binSearchRight(arr, key, m + 1, right, n);
            }
            else{
                if(arr[m] > key)
                    return binSearchRight(arr, key, left, m - 1, n);
                else
                    if(arr[m + 1] != key || (m + 1) == n )
                        return m + 1;
                    else
                        return binSearchRight(arr, key, m + 1, right, n);
                }
            }
        else
            return -1 ;
 
}
int main()
{
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
 
    int arr[100000];
    int n, m, x;
    cin >> n;
 
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
 
 
    cin >> m;
 
    for(int i = 0;i < m;i++){
        cin >> x;
        cout << binSearchLeft(arr, x, 0, n-1) << " " << binSearchRight(arr, x, 0, n-1, n);
        cout << endl;
    }
 
 
    return 0;
}