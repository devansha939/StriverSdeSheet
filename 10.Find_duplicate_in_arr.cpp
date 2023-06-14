// naive using sorting
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			return arr[i];
		}
	}
	return 0;
}

// better using hashing
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	vector<int>vec(n+1,0);
	for(int i=0;i<n;i++){
		vec[arr[i]]++;
		if(vec[arr[i]]>1)return arr[i];
	}
	return 0;
}

//best using linked list cycle method
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int slow = arr[0],fast=arr[0];
	do{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}while(slow!=fast);

	fast=arr[0];
	while(slow!=fast){
		slow=arr[slow];
		fast=arr[fast];
	}
	return slow;
}
