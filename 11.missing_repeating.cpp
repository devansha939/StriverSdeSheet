//using hashing
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int>vec(n+1,0);
	int temp{},temp2;
	for(int i=0;i<n;i++){
		vec[arr[i]]++;
		if(vec[arr[i]]>1)temp=arr[i];
	}
	for(int i=1;i<=n;i++){
		if(vec[i]==0)temp2=i;
	}

	return {temp2,temp};
}

// using maths


// using bit manipulation
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xr=0;
	for(int i=0;i<n;i++){
		xr^=arr[i];
		xr^=(i+1);
	}

	int firs_set_bit=0;
	while(1){
		if((xr&(1<<firs_set_bit))){
			break;
		}
		firs_set_bit++;
	}

	int zero{},one{};
	for(int i=0;i<n;i++){
		if((arr[i]&(1<<firs_set_bit))!=0){
			one^=arr[i];
		}
		else{
			zero^=arr[i];
		}
	}

	for(int i=1;i<=n;i++){
		if((i&(1<<firs_set_bit))!=0){
			one^=i;
		}
		else{
			zero^=i;
		}
	}

	int count{};
	for(int i=0;i<n;i++){
		if(arr[i]==zero){
			count++;
		}
	}

	if(count==2)return {one,zero};
	else return {zero,one};

}


// using bit manipulation but finding first set directly using property
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xr=0;
	for(int i=0;i<n;i++){
		xr^=arr[i];
		xr^=(i+1);
	}

	int firs_set_bit= xr & ~(xr-1);

	int zero{},one{};
	for(int i=0;i<n;i++){
		if((arr[i]&(firs_set_bit))!=0){
			one^=arr[i];
		}
		else{
			zero^=arr[i];
		}
	}

	for(int i=1;i<=n;i++){
		if((i&(firs_set_bit))!=0){
			one^=i;
		}
		else{
			zero^=i;
		}
	}

	int count{};
	for(int i=0;i<n;i++){
		if(arr[i]==zero){
			count++;
		}
	}

	if(count==2)return {one,zero};
	else return {zero,one};

}
