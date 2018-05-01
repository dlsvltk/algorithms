//quick sort
#include<bits/stdc++.h>
using namespace std;

int q_sort(int*arr, int l, int r){
	int li = l+1;
	int ri = r - 1;
	int pv = arr[(l + r) >> 1];

	swap(arr[l], arr[(l + r) >> 1]);

	while (li <= ri){
		while (li < r && arr[li] < pv) li++;
		while (ri >  l && arr[ri] >= pv) ri--;

		if (li <= ri){
			swap(arr[li], arr[ri]);
		}
	}
	swap(arr[l], arr[ri]);

	if (l < ri)	q_sort(arr, l, ri);
	if (li < r)	q_sort(arr, li, r);
	return 0;
}

int a[1001];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	q_sort(a, 0, n);
	for (int i = 0; i < n; ++i) cout << a[i] << endl;

	return 0;
}
