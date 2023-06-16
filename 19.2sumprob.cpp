// Pair sum->https://www.codingninjas.com/codestudio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge&leftPanelTab=1
// naive aprroach
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here
   int n=arr.size();
   vector<vector<int>>ans;
   for(int i=0;i<n;i++){
      int more=arr[i];
      for(int j=i+1;j<n;j++){
         int temp = arr[j];
         if(temp+more==s){
            if(temp>more)ans.push_back({more,temp});
            else ans.push_back({temp,more});
         }
      }
   }
   sort(ans.begin(),ans.end());
   return ans;
}

// using map better than prev
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here
   int n=arr.size();
   map<int,int>mpp;
   vector<vector<int>>ans;
   for(int i=0;i<n;i++){
      if(mpp[s-arr[i]]){
         int times = mpp[s-arr[i]];
         while(times--){
            int temp=arr[i],more=s-arr[i];
            if(temp>more)ans.push_back({more,temp});
            else ans.push_back({temp,more});
         }
      }
      mpp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}

// prob(slight vaiation)->https://leetcode.com/problems/two-sum/description/
//optimal using two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=0,j=n-1;;){
            if(vec[i].first+vec[j].first<target){
                i++;
            }
            else if(vec[i].first+vec[j].first>target){
                j--;
            }
            else{
                ans.push_back(vec[i].second);
                ans.push_back(vec[j].second);
                break;
            }
        }
        return ans;
    }
};
