// recursive + dp solution with memoization
#include <bits/stdc++.h> 
int fun(int i,int j,vector<vector<int>>&dp){
	if(i==0&&j==0){
		return 1;
	}

	if(i<0||j<0)return 0;

	if(dp[i][j]!=-1)return dp[i][j];

	int up = fun(i-1,j,dp);
	int left = fun(i,j-1,dp);
	return dp[i][j]=up+left;

}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return fun(m-1,n-1,dp);
}

// pnc solution
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	int total = n+m-2; //ryt=m-1,down=n-1;
	int r = n-1;
	int ans{1};
	for(int i=1;i<=r;i++){
		ans *= (total - r + i);
		ans/=i;
	}
	return ans;
}
