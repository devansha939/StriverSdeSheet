// naive 
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long  ans{1};
	while(n>0){
		ans*=x;
		ans%=m;
		n-=1;
		// cout<<ans<<"in"<<endl;
	}
	return ans%m;
}

// optimal
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long  ans{1};
	long long temp=x;
	while(n>0){
		if(n%2){
			ans*=temp;
			ans%=m;
			n-=1;
		}
		else{
			temp*=temp;
			temp%=m;
			n/=2;
		}
	}
	return ans%m;
}
