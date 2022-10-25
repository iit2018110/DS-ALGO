#include <bits/stdc++.h>
using namespace std;
 
long long int invCount = 0;
 
void merge(long long int * arr, long long int start, long long int mid, long long int end) {
	long long int temp[end-start+1];
	long long int i=start,j=mid+1,k = 0;
 
	while(i <= mid and j <= end) {
 
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i];
			i++;
		}
		else {
			invCount += (mid - i + 1);
			temp[k++] = arr[j];
			j++;
		}
	}
 
	while(i <= mid) {
		temp[k++] = arr[i];
		i++;
	}
 
	while(j <= end) {
		temp[k++] = arr[j];
		j++;
	}
 
	for(long long int i = 0; i < k; ++i) {
		arr[start+i] = temp[i];
	}
}
 
void mergeSort(long long int * arr, long long int start, long long int end) {
	if(start >= end) return;
 
	long long int mid = (start + end)/2;
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	merge(arr,start,mid,end);
}
 
int main() {
	invCount = 0;
	long long int n; cin>>n;
	long long int arr[n];
	for(long long int i = 0; i < n; ++i) cin>>arr[i];
 
	mergeSort(arr,0,n-1);
 
	cout<<invCount<<endl;
	
	return 0;
}
 