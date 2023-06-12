//using simply STL sort function
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

// Brute force solution is using any sorting algo 
like for merge sort = TC=NLogn and SC=N

//Better solution by maintain count of 1,2,0 since it has only 0,1,2 int

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int zero{},one{},two{};
   for(int i=0;i<n;i++){
      if(arr[i]==0)zero++;
      else if (arr[i]==1)one++;
      else two++;
   
   }
   int ind{};
   for(int i=0;i<zero;i++){
      arr[ind]=0;
      ind++;
   }
   for(int i=0;i<one;i++){
      arr[ind]=1;
      ind++;
   }
   for(int i=0;i<two;i++){
      arr[ind]=2;ind++;
   }
}

//Optimal solution -> dutch national flag algo(DNF)

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int low{},mid{},high{n-1};
   while(mid<=high){
      if(arr[mid]==0){
         swap(arr[low],arr[mid]);
         low++;mid++;
      }
      else if(arr[mid]==1){
         mid+=1;
      }
      else if(arr[mid]==2){
         swap(arr[mid],arr[high]);
         high--;
      }
   }
}
