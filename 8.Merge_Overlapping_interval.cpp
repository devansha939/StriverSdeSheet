//bruteforce approach O(n*logn)+O(2*n)
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &vec)
{
    // Write your code here.
    sort(vec.begin(),vec.end());
    vector<vector<int>>ans;
    int n = vec.size();
    ans.push_back(vec[0]);
    for(int i = 1 ; i<n;i++){
        if(vec[i][1]<=ans[ans.size()-1][1]){
            continue;
        }
        bool b=0;
        for(int j=i;j<n;j++){
            if(vec[j][0]>ans[ans.size()-1][1]) break;
            else{
                b=1;
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],vec[j][1]);
            } 
        }
        if(b==0)ans.push_back(vec[i]);
    }
    return ans;
}


//optimal approach O(nlogn)+O(n)
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &vec)
{
    // Write your code here.
    sort(vec.begin(),vec.end());
    vector<vector<int>>ans;
    int n = vec.size();
    ans.push_back(vec[0]);
    for(int i = 1 ; i<n;i++){
        if(vec[i][0]>ans[ans.size()-1][1]){
            ans.push_back(vec[i]);
        }
        else{
            ans[ans.size()-1][1]=max(ans[ans.size()-1][1],vec[i][1]);
        }
    }
    return ans;
}
