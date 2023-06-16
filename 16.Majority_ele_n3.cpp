// using hashing 
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    unordered_map<int,int>mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}
    vector<int>ans;
	for(auto it:mpp){
		if(it.second>n/3){
			ans.push_back(it.first);
		}
	}
    return ans;
}

// optimal using morre's voting algo
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    int ele{INT_MIN},count{},count2{},ele2{INT_MIN};
	for(int i=0;i<n;i++){
		if(count==0 && ele2!=arr[i]){
			ele=arr[i];
            count=1;
		}
        else if(count2==0 && ele!=arr[i]){
            ele2=arr[i];
            count2=1;
        }
		else if(arr[i]==ele){
			count++;
		}
        else if(arr[i]==ele2){
			count2++;
		}
		else{
			count--;
            count2--;
		}
	}
	count=0;count2=0;
    vector<int>ans;
	for(int i=0;i<n;i++){
		if(arr[i]==ele){
			count++;
		}
        if(arr[i]==ele2)count2++;
	}
	if(count>n/3)ans.push_back(ele);
    if(count2>n/3)ans.push_back(ele2);
	return ans;;
}
