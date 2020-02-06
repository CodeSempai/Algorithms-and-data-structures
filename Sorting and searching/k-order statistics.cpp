#include<stdlib.h>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr, int l, int r){
int pivot = arr[l];
int i = l - 1;
int j = r + 1;

while (true){
do{
i++;
}while(arr[i]<pivot);
do{
j--;
}while (arr[j]>pivot);

if (i>=j)
return j;

swap(arr[i], arr[j]);

}
}

int Random_Partition(vector<int> &arr,int l, int r){
srand(time(0));
int i = l + rand() % (r - l);

swap(arr[i], arr[l]);
return partition(arr, l, r);
}




int Rand_Select(vector<int> &arr,int l, int r, int k){
if (l == r)
return arr[l];
int q = Random_Partition(arr, l, r);
int i = q - l + 1;

if (k <= i){
return Rand_Select(arr,l, q, k);

}else
    return Rand_Select(arr, q + 1, right, k-i);

}


int main()
{
freopen("kth.in.txt", "r", stdin);
freopen("kth.out.txt", "w", stdout);

int n, k , A, B, C, a, b;


cin >> n >> k >> A >> B >> C >> a >> b;


vector<int> arr(n);

arr[0] = a;

arr[1] = b;


for(int i = 2; i < n;i++){
arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
}

cout << findOrderStatistics(arr, 0, n - 1, k);


return 0;
}
