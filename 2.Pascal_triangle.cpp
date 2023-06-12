prob-> https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_8230805?challengeSlug=striver-sde-challenge&leftPanelTab=0


//code to find factorial
#include <bits/stdc++.h>
long long fun ncr(int n, int r){
  long long ans=1;
  for(int i=0;i<r;i++){
    ans*=(n-i);
    ans/=(i);
  }
  return ans;
}

//code to print whole pascal triangle
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long>>vec;
  for(int i = 1 ; i<= n ;i++){
    vector<long long>temp;
    long long ans = 1 ;
    temp.push_back(ans);
    for(int j=1;j<i;j++){
      ans*=(i-j);
      ans/=j;
      temp.push_back(ans);
    }
    vec.push_back(temp);
  }
  return vec;
}

prob->https://codeforces.com/gym/104386/problem/C
sol->https://codeforces.com/gym/104386/submission/207076661
//code of precomputation of ncr using fermat theorem and then called pascal function
#define ll long long
long long divide = 1e9 + 7;
const ll N = 200001;

vector<ll> inversenum(N + 1); // strore inverse 1 to N;

vector<ll> inversefact(N + 1); // store inverse factorial 1 to N;

vector<ll> fact(N + 1); // store factorial of first N number;

void factorial(ll divide)
{ // n factorial
    fact[0] = 1;
    for (ll i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % divide;
    }
}

void inverse(ll divide)
{ // to create inverse of a num
    inversenum[0] = inversenum[1] = 1;
    for (ll i = 2; i <= N; i++)
    {
        inversenum[i] = inversenum[divide % i] * (divide - divide / i) % divide;
    }
}

void inversefactorial(ll divide)
{ // to create inverse factorial i.e inverse (n-r)! and inverse (r)!
    inversefact[0] = inversefact[1] = 1;
    for (ll i = 2; i <= N; i++)
    {
        inversefact[i] = (inversefact[i - 1] * inversenum[i]) % divide;
    }
}

ll pascal(ll a, ll b)
{
    ll ans = ((fact[a] * inversefact[b]) % divide * inversefact[a - b]) % divide;
    return ans;
}
