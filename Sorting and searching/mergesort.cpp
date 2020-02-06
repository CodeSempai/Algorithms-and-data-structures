#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int nmax = 300000;
int A[nmax];
int d[nmax];



void Merg(int arr[], int begin, int end)
{
	int i = begin,
		t = 0,
		mid = begin + (end - begin) / 2,
		j = mid + 1;

	while (i <= mid && j <= end){

		if (arr[i] <= arr[j]) {
			d[t] = arr[i]; i++;
		}
		else {
			d[t] = arr[j]; j++;
		}
		t++;
	}

	while (i <= mid){
		d[t] = arr[i]; i++; t++;
	}

	while (j <= end){
		d[t] = arr[j]; j++; t++;
	}

	for (i = 0; i < t; i++)
        arr[begin + i] = d[i];
}

void MergSort(int *arr, int left, int right)
{
	int  temp;
	if (left<right)
		if (right - left == 1) {
			if (arr[right]<arr[left]){
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
		}
		else {
			MergSort(arr, left, left + (right - left) / 2);
			MergSort(arr, left + (right - left) / 2 + 1, right);
			Merg(arr, left, right);
		}
}





int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

   MergSort(A,0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';



    return 0;
}
