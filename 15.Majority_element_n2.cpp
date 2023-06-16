// using hashing
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}
	for(auto it:mpp){
		if(it.second>n/2){
			return it.first;
		}
	}
	return -1;
}

// otpimal using Moore's voting algo
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int ele{arr[0]},count{1};
	for(int i=1;i<n;i++){
		if(count==0){
			ele=arr[i];
		}
		if(arr[i]==ele){
			count++;
		}
		else{
			count--;
		}
	}
	count=0;
	for(int i=0;i<n;i++){
		if(arr[i]==ele){
			count++;
		}
	}
	if(count>n/2)return ele;
	return -1;
}
