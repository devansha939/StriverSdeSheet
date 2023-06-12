prob->https://www.codingninjas.com/codestudio/problems/next-permutation_8230741?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &vec, int n)
{
    //  Write your code here.
    int check=-1;
    for(int i=n-1;i>0;i--){
        if(vec[i]>vec[i-1]){
            check=i-1;
            break;
        }
    }
    // cout<<check<<endl;
    if(check==-1){
        reverse(vec.begin(),vec.end());
        return vec;
    }
    for(int i=n-1;i>=check;i--){
        if(vec[i]>vec[check]){
            swap(vec[i],vec[check]);
            break;
        }
    }

    reverse(vec.begin()+check+1,vec.end());

    return vec;
}
