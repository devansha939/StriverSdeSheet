// brute force is simply merge sort

//optimal 1
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int left=m-1,right=0;
	while(left>=0&&right<n){
		if(arr1[left]>arr2[right]){
			swap(arr1[left],arr2[right]);
			left--;right++;
		}
		else{
			break;
		}
	}
	
	sort(arr1.begin(),arr1.begin()+m);
	sort(arr2.begin(),arr2.begin()+n);
	for(int i=m;i<m+n;i++){
		arr1[i]=arr2[i-m];
	}
	return arr1;

  
  //optimal 2 gap method,shell sort
  
 

//  w/o extra space in O(n+m) according to me
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int j{m-1},k{n-1};
	for(int i=n+m-1;i>=0;i--){
		if(j<0&&k>=0){
			arr1[i]=arr2[k];
			k--;
		}
		if(j>=0&&k>=0&&arr1[j]<=arr2[k]){
			arr1[i]=arr2[k];
			k--;
		}
		else if(j>=0&&k>=0&&arr1[j]>arr2[k]){
			arr1[i]=arr1[j];
			j--;
		}
	}
	return arr1;
}
