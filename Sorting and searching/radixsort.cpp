#include<fstream>
#include <iostream>
using namespace std;
int k = 27;


void Merg(int begin, int end, int num){
	int i = begin,
		t = 0,
	    mid = begin + (end - begin) / 2,
		j = mid + 1;

	while (i <= mid && j <= end) {

		if (country[i][num] <= country[j][num]) {
			d[t] = country[i]; i++;
		}
		else {
			d[t] = country[j]; j++;
		}
		t++;
	}

	while (i <= mid) {
		d[t] = country[i]; i++; t++;
	}

	while (j <= end) {
		d[t] = country[j]; j++; t++;
	}

	for (i = 0; i < t; i++)
		country[begin + i] = d[i];
}

void MergSort(int left, int right, int num){
	string  temp;
	if (left<right)
		if (right - left == 1) {
			if (country[right] < country[left]) {
				temp = country[left];
				country[left] = country[right];
				country[right] = temp;
			}
		}
		else {
			MergSort(left, left + (right - left) / 2, num);
			MergSort(left + (right - left) / 2 + 1, right, num);
			Merg(left, right, num);
		}
}






int main()
{
    freopen("sort.in.txt", "r", stdin);
    freopen("sort.out.txt", "w", stdout);

    string arr[1000];
    int n, m;

    cin >> n >> m;

    for(int i = 0;i < n;i++)
        cin >> arr[i];

    radixsort(arr, n, m);

    for(int i = 0;i < n;i++)
        cout << B[i] << " ";


    return 0;
}
