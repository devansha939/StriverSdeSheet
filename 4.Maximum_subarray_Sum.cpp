Prob->https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge&leftPanelTab=0
//Kadane Algo
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long maxi {INT_MIN},sum{};
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi)maxi=sum;
        if(sum<0)sum=0;
        // cout<<maxi<<" "<<sum<<endl;
    }
    if(maxi<0)return 0;
    return maxi;
}
